import paho.mqtt.client as mqtt
import threading

def on_message(client, userdata, message):
    print("message received", str(message.payload.decode("utf-8")))
    print("message topic= ", message.topic)
    print("message qos=", message.qos)
    print("message retain flag=", message.retain)

def mqtt_sub():
    print("mqtt sub start")
    #mqtt broker

    mqtt_broker_address = "127.0.0.1"
    client = mqtt.Client("client1")
    client.connect(mqtt_broker_address)
    client.subscribe("topic")
    client.on_message = on_message
    client.loop_forever()


try:
    mqtt_thread = threading.Thread(target=mqtt_sub)
    mqtt_thread.start()

except Exception as e:
    print('에러는?: ',e)
