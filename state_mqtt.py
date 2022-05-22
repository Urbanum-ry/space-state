import paho.mqtt.client as mqttclient
import json
import time

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected to MQTT Broker!")
        global connected
        connected = True
    else:
        print("Failed to connect", rc)

def on_message(client, userdate, message):
    print(message.payload)
    with open("/home/urbanum/state.json", "w") as outfile:
        json.dump({'state' : message.payload.decode('utf-8')}, outfile, indent =4)

connected = False

broker = '10.47.45.113'
port = 1883
topic = '/hervanta/main_building/urbanum'
client_id = 'urbanum'

client = mqttclient.Client(client_id)
client.on_connect = on_connect
client.on_message = on_message

client.connect(broker, port=port)

client.loop_start()

while connected != True:
    time.sleep(0.1)

client.subscribe(topic)

try:
    while True:
        time.sleep(1)

except KeyboardInterrupt:
    print("exiting")
    client.disconnect()
    client.loop_stop()
