import os
from pocketsphinx import LiveSpeech, get_model_path
import time
import serial

model_path = get_model_path()
ser = serial.Serial('COM4',9600)

phons = [0,0,0]

speech = LiveSpeech(
    lm=False,
    dic=False,
    allphone='deps/pocketsphinx/model/en-us/en-us-phone.lm.bin',
    lw=2.0,
    pip=0.3,
    beam=1e-10,
    pbeam=1e-10,
    mmap=True,
    
)

for phrase in speech:
    #phrase.segments(detailed=False)
    #print(phrase.segments)
    result = []
    #[seg.word for seg in phrase.seg()]
    result = ([seg.word for seg in phrase.seg()])
    if len(result) == 2:
        print('Best Phonemes:', result[1])
        ser.write(result[1].encode())
    if len(result) > 2:
        print('Best Phonemes:', result[1],result[2])
        ser.write(result[1].encode())
        ser.write(result[2].encode())

    print(ser.read(2))
    
    #ser.write('0'.encode())

 


"""
    verbose=False,
    sampling_rate=16000,
    buffer_size=2048,
    no_search=False,
    full_utt=False,
    hmm=os.path.join(model_path, 'en-us'),
    lm=os.path.join(model_path, 'en-us.lm.bin'),
    dic=os.path.join(model_path, 'cmudict-en-us.dict')
"""
