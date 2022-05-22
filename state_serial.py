import serial
import json

serialPort = serial.Serial(port = "/dev/ttyACM0", baudrate=115200,timeout=2)

while(1):
    if(serialPort.in_waiting > 0):
        serialString = (serialPort.readline().decode('ascii').removesuffix('\r\n'))
        print(serialString)
        with open("/var/www/html/state.json", "w") as outfile:
            json.dump({'state' : serialString}, outfile, indent = 4)
