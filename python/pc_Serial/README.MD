# Python Files

I had to tweak the original python files to work with my tweaked arduino file.  The ServoTest1.py will go through all the cases on the arduino making sure that the servos move.  It takes 90 seconds to go through all the servos.  I put a 2 second pause for each one to allow the serial time to communicate.  initially I had it set to .25 and it through so fast the commands never got to the servos.

The second file facetest1.py is used to take a keyboard input and send the code to the arduino.
