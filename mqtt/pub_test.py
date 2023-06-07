import paho.mqtt.client as mqtt

mqttc = mqtt.Client("Client2")
mqttc.connect("127.0.0.1",1883)
mqttc.publish("camera/data", "test text")
