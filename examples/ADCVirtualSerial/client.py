#!/usr/bin/env python

import RPi.GPIO as GPIO
import time
import serial

hwbPin = 23
GPIO.setmode(GPIO.BCM)
GPIO.setup(hwbPin, GPIO.OUT)

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
ser.open()

try:
  while 1:
    GPIO.output(hwbPin, GPIO.LOW)
    time.sleep(0.1)
    GPIO.output(hwbPin, GPIO.HIGH)
    response = ser.readline()
    print response,
except KeyboardInterrupt:
    ser.close()
    GPIO.cleanup()
