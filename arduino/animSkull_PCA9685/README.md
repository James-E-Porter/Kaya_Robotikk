# Face_01_copy ....

This is the arduino code that i tweaked for my own personal skull.  the case values set up positions for the different servos.  case 10 resets all servos to their resting position.






# animSkull_PCA9685.ino Code Summary

The Arduino code in the `animSkull_PCA9685.ino` file is designed to control various servo motors to animate a skull. Here's a breakdown of the code:

## 1. Libraries and Initialization:
- The code includes the `Wire.h` and `Adafruit_PWMServoDriver.h` libraries, which are essential for I2C communication and controlling the PCA9685 PWM servo driver, respectively.
- An instance of the `Adafruit_PWMServoDriver` class is created, named `pwm`.
- Constants `SERVOMIN` and `SERVOMAX` are defined to represent the minimum and maximum pulse lengths for the servos.

## 2. Servo Channels:
- The code defines several servo channels, each representing a different part of the skull. These include channels for eyelids, eyebrows, lips, jaw, and more.

## 3. Offsets:
- There are offset values defined for each servo. These offsets are added to the servo angles to adjust their default positions.

## 4. Setup Function:
- The `setup()` function initializes the PWM driver, sets the PWM frequency, and sets the initial positions of all the servos using the defined offsets.
- The serial communication is also initialized for debugging and receiving commands.

## 5. angleToPulse Function:
- This function converts an angle (0 to 180 degrees) to a pulse width for the servo.

## 6. Main Loop:
- The `loop()` function waits for serial input. When a command is received, it adjusts the positions of the servos based on the command value.
- Different command values correspond to different animations or positions for the skull. For example, a command value of `2` might close the eyelids, while a value of `3` might open them.
- Some commands also send signals to other devices using the I2C protocol.

In summary, this code is designed to animate a skull using various servos. The skull can perform different animations based on the received serial commands. The animations include movements of the eyelids, eyebrows, lips, jaw, and more.
