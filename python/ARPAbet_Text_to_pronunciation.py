import nltk
import time
import serial

arpabet = nltk.corpus.cmudict.dict()
ser = serial.Serial('COM4',9600) #Change this to the port your arduino is connected to

while True:
    #Take input sentence and separate into a list
    print('Enter your sentence:')
    your_sentence = input()
    your_sentence = your_sentence.split()
    print("You Typed:", your_sentence)

    #Find arpabet translation of each word in the sentence and store in result array
    result = []
    for words in (your_sentence):
        result.append(arpabet[words])
    array_length = len(result)

    #Print each phoneme seperated by a "."
    for x in range(0, array_length):
        word_length = len(result[x][0])
        for y in range(0, word_length):
            print(result[x][0][y], end = '')
            ser.write(result[x][0][y].encode())
            print(".", end = '')
            ser.write('.'.encode())
    print("$", end = '')
    ser.write('$'.encode())

    print(" wrote to arduino")

