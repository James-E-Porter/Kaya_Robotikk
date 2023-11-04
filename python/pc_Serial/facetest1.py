from time import sleep

import serial
import keyboard
import os

ser = serial.Serial('COM5', 9600) # Establish the connection on a specific port


previous_status = "0"
previous_message = ""

def write_serial(status, printed):
    global previous_status
    if status != previous_status:
        os.system('clear')	
        print(printed)
        ser.write(str(status))
        previous_status = status

def clear_serial(status):
    global previous_status
    if status != previous_status:
        os.system('clear')
        print("WAITING FOR USER INPUT! (TRY Q,W,E,R,T,A,S,D,F)")
        ser.write(str(status).encode('utf-8'))
        previous_status = status
        
def sys_message(message):
    global previous_message
    if message != previous_message:
        os.system('clear')
        print(message)
        previous_message = message        

while True:
    if keyboard.is_pressed('q'): 	
        ser.write(b"2")
        sleep(0.25)
        clear_serial(0)
    elif keyboard.is_pressed('w'): 	
        ser.write(b"3")
        sleep(0.25)
        clear_serial(0)
    elif keyboard.is_pressed('e'): 	
        ser.write(b"4")
        sleep(0.25)  
        clear_serial(0) 
    elif keyboard.is_pressed('r'): 	
        ser.write(b"5")
        sleep(0.25)
        clear_serial(0)
    elif keyboard.is_pressed('a'): 	
        ser.write(b"6") 
        sleep(0.25)
        clear_serial(0)
    elif keyboard.is_pressed('s'): 	
        ser.write(b"7")
        sleep(0.25)
        clear_serial(0)
    elif keyboard.is_pressed('d'): 	
        ser.write(b"8")
        sleep(0.25)
        clear_serial(0)
    elif keyboard.is_pressed('f'): 	
        ser.write(b"9")
        sleep(0.25)
        clear_serial(0)
    elif keyboard.is_pressed('z'): 	
        ser.write(b"11")
        sleep(0.25)
        clear_serial(0)
    elif keyboard.is_pressed('x'): 	
        ser.write(b"12")
        sleep(0.25)
        clear_serial(0)
    elif keyboard.is_pressed('t'): 	
        ser.write(b"13")         
        sleep(0.25)
        clear_serial(0)
    elif keyboard.is_pressed('y'): 	
        ser.write(b"14")         
        sleep(0.25)
        clear_serial(0)
    elif keyboard.is_pressed('g'): 	
        ser.write(b"15")         
        sleep(0.25)
        clear_serial(0)
    elif keyboard.is_pressed('h'): 	
        ser.write(b"16")         
        sleep(0.25)
        clear_serial(0)
    elif keyboard.is_pressed('b'): 	
        ser.write(b"17")         
        sleep(0.25)
        clear_serial(0)  
    elif keyboard.is_pressed('n'): 	
        ser.write(b"18")         
        sleep(0.25)
        clear_serial(0)                
    elif keyboard.is_pressed('u'): 	
        ser.write(b"19")         
        sleep(0.25)
        clear_serial(0)
    elif keyboard.is_pressed('i'): 	
        ser.write(b"20")         
        sleep(0.25)
        clear_serial(0)   
    elif keyboard.is_pressed('j'): 	
        ser.write(b"21")         
        sleep(0.25)
        clear_serial(0) 
    elif keyboard.is_pressed('k'): 	
        ser.write(b"22")        
        sleep(0.25)
        clear_serial(0)                                  
    elif keyboard.is_pressed('1'): 	
        ser.write(b"23")         
        sleep(0.25)
        clear_serial(0)  
    elif keyboard.is_pressed('2'): 	
        ser.write(b"24")         
        sleep(0.25)
        clear_serial(0)                  
    elif keyboard.is_pressed('o'): 	
        ser.write(b"10")
        sleep(0.25)  
        clear_serial(0)                                             
    elif keyboard.is_pressed('p'):
        ser.write(b"1")	
        sleep(1)
                    
        os.system('clear')
        exit()
    else:		
        sys_message("WAITING FOR USER INPUT! (TRY Q,W,E,R,T,A,S,D,F)")   
