from time import sleep
import serial

# Establish the connection on a specific port
ser = serial.Serial('COM5', 9600)
sleep(4)  # give some time for the connection to establish

# Define a list of commands to be sent to the Arduino
commands = [
    b"2", b"3", b"4", b"5", b"6", b"7", b"8", b"9",b"10",
    b"13", b"12", b"11", b"14", b"15", b"16", b"10",
    b"22", b"21", b"20", b"17", b"18", b"19", b"10",
    b"24", b"23", b"25", b"16", b"10", b"28", b"27",
    b"29", b"30", b"10", b"31", b"32", b"33", b"34",
    b"35", b"36", b"37", b"10"
]

# Function to clear the terminal and print a waiting message
def clear_and_print(message):
    print("\033[H\033[J", end="")  # ANSI escape code to clear the screen
    print(message)

# Send each command with a delay
for command in commands:
    ser.write(command)
    clear_and_print(f"Sent command: {command.decode('utf-8')}")
    sleep(2)  # delay between commands

# Close the serial connection
ser.close()
