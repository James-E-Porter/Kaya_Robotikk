/*
 * Nilheim Mechatronics ARPAbet interpreter
 * 
 * This program is designed to be used with the ARPAbet_Text_to_pronunciation.py file
 * Type a sentence into the aforementioned program and, if configured correctly, it will send a signal
 * through the serial port to the arduino, which will pose the Nilheim Mechantronics animatronic mouth
 * according to the typed sentence. 
 * 
 * Visit www.Nilheim.co.uk for more info
 * 
 */

#include <string.h>
#include <stdio.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

float noStress = 50;
float neutralStress = 100;
float primaryStress = 200;
float secondaryStress = 150;

uint16_t phonemeA[] = {400, 350, 370, 420, 300, 250, 300, 400, 400}; //AEIH
uint16_t phonemeO[] = {375, 375, 550, 250, 150, 400, 300, 340, 400}; //OUW  !!!!!
uint16_t phonemeB[] = {350, 400, 300, 330, 350, 330, 350, 340, 440}; //BMP
uint16_t phonemeG[] = {360, 390, 300, 330, 350, 330, 300, 340, 400}; //GKXYJR
uint16_t phonemeS[] = {365, 385, 300, 330, 350, 330, 300, 450, 400}; //CDNSTZKQ
uint16_t phonemeTh[] = {360, 390, 350, 350, 350, 350, 350, 495, 350};//Th
uint16_t phonemeL[] = {375, 375, 370, 420, 300, 250, 300, 480, 400};//L
uint16_t phonemeF[] = {350, 400, 300, 330, 350, 330, 260, 340, 400};//FV    

void setup() {
 Serial.begin(9600);
 pinMode(LED_BUILTIN, OUTPUT);  
 digitalWrite(LED_BUILTIN, LOW);
 pwm.begin();
 pwm.setPWMFreq(60); 
 phonemePose(phonemeB);
 Serial.println("Getting Ready");
 delay(1000);
  Serial.println(" Ready!");
 
}

void loop() {
       
  matchPhoneme();
}
  
void matchPhoneme(){

  //If serial data is available to read
  if (Serial.available() > 0 ) {

  char tomp = NULL;
  char tomp2 = NULL;
  char stress = NULL;
  char term = NULL;
  char terminator = NULL;
  
    //Read first character
    tomp = Serial.read();
    Serial.print("Input Phoneme: ");
    Serial.print(tomp);

    //Check if sentence is over
    if(tomp == '$'){
      phonemePose(phonemeB);
      Serial.print("End of sentence");
    } else {
      //Read second character
      delay(1);
      tomp2 = Serial.read(); 
      Serial.println(tomp2);

      //Check for all single-character ARPAbet Phonemes
      if ((tomp == 'B')||(tomp == 'M')||(tomp == 'P')){
        phonemePose(phonemeB); 
      } else if ((tomp == 'F')||(tomp == 'V')){
        phonemePose(phonemeF);
      } else if ((tomp == 'G')||(tomp == 'K')||(tomp == 'Y')||(tomp == 'R')){
        phonemePose(phonemeG);
      } else if (tomp == 'L'){
        phonemePose(phonemeL);
      } else if (tomp == 'K'){
        phonemePose(phonemeS);
      } else if (tomp == 'W'){
        phonemePose(phonemeO);
      }

      //Check for two-character ARPAbet Phonemes
      if ((tomp2 != '0')&&(tomp2 != '1')&&(tomp2 != '2')&&(tomp2 != '!')&&(tomp2 != '$')){ 
        if (tomp == 'A'){
          if ((tomp2 == 'A')||(tomp2 == 'E')||(tomp2 == 'H')||(tomp2 == 'Y')){
            phonemePose(phonemeA); 
          } else if ((tomp2 == 'O')||(tomp2 == 'W')){
            phonemePose(phonemeO);
          }
          
        } else if (tomp == 'C'){
          phonemePose(phonemeS);
          
        } else if (tomp == 'D'){
          if (tomp2 == 'H'){
            phonemePose(phonemeTh);
          } else {
            phonemePose(phonemeS);
            if ((tomp2 == '0')||(tomp2 == '1')||(tomp2 == '2')){
              stress = tomp2;
            } else { 
              term = tomp2;
            }
          }
          
        } else if (tomp == 'E'){
          phonemePose(phonemeA);
          if ((tomp2 == '0')||(tomp2 == '1')||(tomp2 == '2')){
              stress = tomp2;
            } else { 
              term = tomp2;
            }
            
        } else if (tomp == 'H'){
          phonemePose(phonemeA);
          
        } else if (tomp == 'I'){
          phonemePose(phonemeA);
          
        } else if (tomp == 'J'){
          phonemePose(phonemeG);
          
        } else if (tomp == 'N'){
          if (tomp2 == 'G'){
            phonemePose(phonemeS);
          } else {
            phonemePose(phonemeS);
            if ((tomp2 == '0')||(tomp2 == '1')||(tomp2 == '2')){
              stress = tomp2;
            } else { 
              term = tomp2;
            }
          }
          
        } else if (tomp == 'O'){
            phonemePose(phonemeO);    
                  
        } else if (tomp == 'S'){
          phonemePose(phonemeS);
          if (tomp2 != 'H'){
            if ((tomp2 == '0')||(tomp2 == '1')||(tomp2 == '2')){
              stress = tomp2;
            } else { 
              term = tomp2;
            }  
          }
          
        } else if (tomp == 'T'){
          if (tomp2 == 'H'){
            phonemePose(phonemeTh);
          } else {
            phonemePose(phonemeS);
            if ((tomp2 == '0')||(tomp2 == '1')||(tomp2 == '2')){
              stress = tomp2;
            } else { 
              term = tomp2;
            }  
          }
          
        } else if (tomp == 'U'){
          phonemePose(phonemeO);
          
        } else if (tomp == 'Z'){
          if (tomp2 == 'H'){
            phonemePose(phonemeTh);
          } else {
            phonemePose(phonemeS);
            if ((tomp2 == '0')||(tomp2 == '1')||(tomp2 == '2')){
              stress = tomp2;
            } else { 
              term = tomp2;
            }  
          }
        }   
      }
      if ((tomp2 == '0')||(tomp2 == '1')||(tomp2 == '2')){
        stress = tomp2;
        delay(1);
        term = Serial.read();
      } else if ((tomp2 == '.')||(tomp2 == '$')){
        term = tomp2;
      } else { 
        delay(1);
        tomp = Serial.read();
        if ((tomp == '0')||(tomp == '1')||(tomp == '2')){
          stress = tomp;
          delay(1);
          term = Serial.read();          
        } else if ((tomp == '.')||(tomp=='$')){
          term = tomp;
        }
    }
    if (stress == '0'){
      delay(noStress);
    } else if (stress == '1'){
      delay(primaryStress);     
    } else if (stress == '2'){
      delay(secondaryStress);
    } else if (stress == NULL) {
      delay(neutralStress);
    }
  }
}
}

void phonemePose(uint16_t phoneme[]) {
  for(uint8_t i = 0; i <=8; i++){
    pwm.setPWM(i, 0, phoneme[i]);
    Serial.print(phoneme[i]);
    Serial.print("   ");
  }
  Serial.println("Finished :)");
}
