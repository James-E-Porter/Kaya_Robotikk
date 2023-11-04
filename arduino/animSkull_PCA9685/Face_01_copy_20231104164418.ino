#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

constexpr int SERVO_MIN = 250;  // Minimum pulse width for servo
constexpr int SERVO_MAX = 500;  // Maximum pulse width for servo

// Channels for each servo
uint8_t servoChannels[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

// Lower bounds for each servo (in pulse width)
int servoLowerBounds[16] = {SERVO_MIN, SERVO_MIN, SERVO_MIN, SERVO_MIN, SERVO_MIN, SERVO_MIN, SERVO_MIN, SERVO_MIN, SERVO_MIN, 300, 262, 275, 300, 387, 275, SERVO_MIN};

// Upper bounds for each servo (in pulse width)
int servoUpperBounds[16] = {SERVO_MAX, SERVO_MAX, SERVO_MAX, SERVO_MAX, SERVO_MAX, SERVO_MAX, SERVO_MAX, SERVO_MAX, SERVO_MAX, 475, 300, 375, 400, 500, 425, SERVO_MAX};

// Neutral positions for each servo (in pulse width)
int servoNeutralPositions[16] = {375, 375, 375, 375, 375, 375, 375, 375, 375, 400, 262, 325, 350, 400, 350, 375};

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60); // Set frequency to 60 Hz
  initializeServos();
  Wire.begin();
}

void loop() {
  static long lastServoCommand = 0;
  if (Serial.available() > 0) {
    long servoCommand = Serial.parseInt();
    if (servoCommand != lastServoCommand) {
      handleServoCommand(servoCommand);
      lastServoCommand = servoCommand;
    }
  }
}

void initializeServos() {
  for (int channel = 0; channel < 16; ++channel) {
    pwm.setPWM(servoChannels[channel], 0, servoNeutralPositions[channel]);
  }
  Serial.println("Servos initialized to neutral positions.");
}

void handleServoCommand(long command) {
  // Implement specific command handling here
  // Example command handling for setting servos to neutral
  switch (command) {
    case 2:
      // Reserved for eye movement
      break;
    case 3: 
      // Reserved for eye movement
      break;
    case 4:
      // Reserved for eye movement
      break;
    case 5:
      // Reserved for eye movement
      break;
    case 6: 
      // Reserved for eye movement
      break;
    case 7:
      // Reserved for eye movement
      break;
    case 8:
      // Reserved for eye movement
      break;
    case 9:
      // Reserved for eye movement
      break;
    case 10:
      moveToNeutralPositions(0, 15); // Move servos 0 to 15 to neutral
      Serial.println("Servos initialized to neutral positions.");
      break;
    case 11:  // raise L Eyebrow #  up 1
      setServoPulse(14, servoNeutralPositions[14] - 25); // This assumes that the value is a correct pulse width
      break;
    case 12:  // raise L Eyebrow #  up 2
      setServoPulse(14, servoNeutralPositions[14] - 50); // This assumes that the value is a correct pulse width
      break;
    case 13:  // raise L Eyebrow #  up 3
      setServoPulse(14, servoNeutralPositions[14] - 75); // This assumes that the value is a correct pulse width
      break;
    case 14:  // raise L Eyebrow #  Down 1
      setServoPulse(14, servoNeutralPositions[14] +  25); // This assumes that the value is a correct pulse width
      break;
    case 15:  // raise L Eyebrow #  Down 2
      setServoPulse(14, servoNeutralPositions[14] +  50); // This assumes that the value is a correct pulse width
      break;
    case 16:  // raise L Eyebrow #  Down 3
      setServoPulse(14, servoNeutralPositions[14] +  75); // This assumes that the value is a correct pulse width
      break;
    case 17:  // raise R Eyebrow #  down 1
      setServoPulse(9, servoNeutralPositions[9] - 25); // This assumes that the value is a correct pulse width
      break;
    case 18:  // raise R Eyebrow #  down 2
      setServoPulse(9, servoNeutralPositions[9] - 50); // This assumes that the value is a correct pulse width
      break;
    case 19:  // raise R Eyebrow #  down 3
      setServoPulse(9, servoNeutralPositions[9] - 75); // This assumes that the value is a correct pulse width
      break;
    case 20:  // raise R Eyebrow #  up 1
      setServoPulse(9, servoNeutralPositions[9] + 25); // This assumes that the value is a correct pulse width
      break;
    case 21:  // raise R Eyebrow #  up 2
      setServoPulse(9, servoNeutralPositions[9] + 50); // This assumes that the value is a correct pulse width
      break;
    case 22:  // raise R Eyebrow #  up 3
      setServoPulse(9, servoNeutralPositions[9] + 75); // This assumes that the value is a correct pulse width
      break;
    
    case 23:  // raise L Mouth Side #  up 1
      setServoPulse(11, servoNeutralPositions[11] - 25); // This assumes that the value is a correct pulse width
      break;
    case 24:  // raise L Mouth Side #  up 2
      setServoPulse(11, servoNeutralPositions[11] - 50); // This assumes that the value is a correct pulse width
      break;
    case 25:  // raise L Mouth Side #  down 1
      setServoPulse(11, servoNeutralPositions[11] + 25); // This assumes that the value is a correct pulse width
      break;
    case 26:  // raise L Mouth Side #  Down 2
      setServoPulse(11, servoNeutralPositions[11] + 50); // This assumes that the value is a correct pulse width
      break;
    case 27:  // raise R Mouth Side #  up 1
      setServoPulse(12, servoNeutralPositions[12] + 25); // This assumes that the value is a correct pulse width
      break;
    case 28:  // raise R Mouth Side #  up 2
      setServoPulse(12, servoNeutralPositions[12] + 50); // This assumes that the value is a correct pulse width
      break;
    case 29:  // raise R Mouth Side #  down 1
      setServoPulse(12, servoNeutralPositions[12] - 25); // This assumes that the value is a correct pulse width
      break;
    case 30:  // raise R Mouth Side #  Down 2
      setServoPulse(12, servoNeutralPositions[12] - 50); // This assumes that the value is a correct pulse width
      break;
    case 31:  // Open Mouth # 1
      setServoPulse(13, servoNeutralPositions[13] + 25); // This assumes that the value is a correct pulse width
      break;
    case 32:  // Open Mouth # 2
      setServoPulse(13, servoNeutralPositions[13] + 50); // This assumes that the value is a correct pulse width
      break;
    case 33:  // Open Mouth # 3
      setServoPulse(13, servoNeutralPositions[13] + 75); // This assumes that the value is a correct pulse width
      break;
    case 34:  // Close Mouth
      setServoPulse(13, servoNeutralPositions[13]); // This assumes that the value is a correct pulse width
      break;
    case 35:  // Lip up  # 1
      setServoPulse(10, servoNeutralPositions[10] + 13); // This assumes that the value is a correct pulse width
      break;
    case 36:  // Lip up  # 2
      setServoPulse(10, servoNeutralPositions[10] + 25); // This assumes that the value is a correct pulse width
      break;
    case 37:  // Lip up  # 3
      setServoPulse(10, servoNeutralPositions[10] + 38); // This assumes that the value is a correct pulse width
      break;
    case 38:  // Lip Netral
      setServoPulse(10, servoNeutralPositions[10]); // This assumes that the value is a correct pulse width
      break;
    default:
      // Handle unknown commands
      Serial.print("Unknown command: ");
      Serial.println(command);
      break;
  }
}

void setServoPulse(int channel, int pulseWidth) {
  if (pulseWidth < servoLowerBounds[channel] || pulseWidth > servoUpperBounds[channel]) {
    Serial.print("Pulse width out of range for channel ");
    Serial.println(channel);
    return;
  }
  pwm.setPWM(servoChannels[channel], 0, pulseWidth);
}

void moveToNeutralPositions(int startChannel, int endChannel) {
  for (int channel = startChannel; channel <= endChannel; ++channel) {
    setServoPulse(channel, servoNeutralPositions[channel]);
  }
}
