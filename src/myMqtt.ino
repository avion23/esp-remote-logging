///*
// * myMqtt.cpp
// *
// *  Created on: Oct 16, 2016
// *      Author: avion
// */
//
//#include <AsyncMqttClient.h>
//#include <myMqtt.h>
//#include <Streaming.h>
//
//const String mqttClientId = "irrigation-system";
//AsyncMqttClient mqttClient;
//
////void onMqttConnect(bool sessionPresent) {
////	Serial << "[MQTT] ** Connected to the broker **" << endl;
////	Serial << "[MQTT] Session present: " << sessionPresent << endl;
//////	uint16_t packetIdSub = mqttClient.subscribe("test/lol", 2);
//////	Serial << "[MQTT] Subscribing at QoS 2, packetId: " << packetIdSub << endl;
//////	mqttClient.publish("test/lol", 0, true, "test 1");
//////	Serial << "[MQTT] Publishing at QoS 0" << endl;
//////	uint16_t packetIdPub1 = mqttClient.publish("test/lol", 1, true, "test 2");
//////	Serial << "[MQTT] Publishing at QoS 1, packetId: " << packetIdPub1 << endl;
//////	uint16_t packetIdPub2 = mqttClient.publish("test/lol", 2, true, "test 3");
//////	Serial << "[MQTT] Publishing at QoS 2, packetId: " << packetIdPub2 << endl;
////}
//
////void onMqttDisconnect(AsyncMqttClientDisconnectReason reason) {
////	Serial << "[MQTT] ** Disconnected from the broker **" << endl;
////	Serial << "[MQTT] Reconnecting to MQTT..." << endl;
////	delay(8000); // avoid spam
////	mqttClient.connect();
////}
////
////void onMqttSubscribe(uint16_t packetId, uint8_t qos) {
////	Serial << "[MQTT] ** Subscribe acknowledged **" << endl;
////	Serial << "[MQTT]   packetId: " << packetId << endl;
////	Serial << "[MQTT]   qos: " << qos << endl;
////}
////
////void onMqttUnsubscribe(uint16_t packetId) {
////	Serial << "[MQTT] ** Unsubscribe acknowledged **" << endl;
////	Serial << "[MQTT]   packetId: " << packetId << endl;
////}
////
////void onMqttMessage(char* topic, char* payload,
////		AsyncMqttClientMessageProperties properties, size_t len, size_t index,
////		size_t total) {
////	Serial << "[MQTT] ** Publish received **" << endl;
////	Serial << "[MQTT]   topic: " << topic << endl;
////	Serial << "[MQTT]   qos: " << properties.qos << endl;
////	Serial << "[MQTT]   dup: " << properties.dup << endl;
////	Serial << "[MQTT]   retain: " << properties.retain << endl;
////	Serial << "[MQTT]   len: " << len << endl;
////	Serial << "[MQTT]   index: " << index << endl;
////	Serial << "[MQTT]   total: " << total << endl;
////}
////
////void onMqttPublish(uint16_t packetId) {
////	Serial << "[MQTT] ** Publish acknowledged **" << endl;
////	Serial << "[MQTT]   packetId: " << packetId << endl;
////}
////
////void publishString(String str, String value) {
////	if (mqttClient.connected()) {
////		String topic = mqttClientId + "/" + str;
////		mqttClient.publish(topic.c_str(), 0, false, ((String) str).c_str());
////		Serial << "[MQTT] publishing: " << topic << " = " << value << endl;
////	}
////}
//
//void onMqttConnect(bool sessionPresent) {
//	Serial.println("Connected to MQTT.");
//	Serial.print("Session present: ");
//	Serial.println(sessionPresent);
//	uint16_t packetIdSub = mqttClient.subscribe("test/lol", 2);
//	Serial.print("Subscribing at QoS 2, packetId: ");
//	Serial.println(packetIdSub);
//	mqttClient.publish("test/lol", 0, true, "test 1");
//	Serial.println("Publishing at QoS 0");
//	uint16_t packetIdPub1 = mqttClient.publish("test/lol", 1, true, "test 2");
//	Serial.print("Publishing at QoS 1, packetId: ");
//	Serial.println(packetIdPub1);
//	uint16_t packetIdPub2 = mqttClient.publish("test/lol", 2, true, "test 3");
//	Serial.print("Publishing at QoS 2, packetId: ");
//	Serial.println(packetIdPub2);
//}
//
//void onMqttDisconnect(AsyncMqttClientDisconnectReason reason) {
//	Serial.println("Disconnected from MQTT.");
//
//	if (WiFi.isConnected()) {
//		mqttReconnectTimer.once(2, connectToMqtt);
//	}
//}
//
//void onMqttSubscribe(uint16_t packetId, uint8_t qos) {
//	Serial.println("Subscribe acknowledged.");
//	Serial.print("  packetId: ");
//	Serial.println(packetId);
//	Serial.print("  qos: ");
//	Serial.println(qos);
//}
//
//void onMqttUnsubscribe(uint16_t packetId) {
//	Serial.println("Unsubscribe acknowledged.");
//	Serial.print("  packetId: ");
//	Serial.println(packetId);
//}
//
//void onMqttMessage(char* topic, char* payload,
//		AsyncMqttClientMessageProperties properties, size_t len, size_t index,
//		size_t total) {
//	Serial.println("Publish received.");
//	Serial.print("  topic: ");
//	Serial.println(topic);
//	Serial.print("  qos: ");
//	Serial.println(properties.qos);
//	Serial.print("  dup: ");
//	Serial.println(properties.dup);
//	Serial.print("  retain: ");
//	Serial.println(properties.retain);
//	Serial.print("  len: ");
//	Serial.println(len);
//	Serial.print("  index: ");
//	Serial.println(index);
//	Serial.print("  total: ");
//	Serial.println(total);
//}
//
//void onMqttPublish(uint16_t packetId) {
//	Serial.println("Publish acknowledged.");
//	Serial.print("  packetId: ");
//	Serial.println(packetId);
//}
//
//void mqttSetup() {
////	mqttClient.onConnect(onMqttConnect);
////	mqttClient.onDisconnect(onMqttDisconnect);
////	mqttClient.onSubscribe(onMqttSubscribe);
////	mqttClient.onUnsubscribe(onMqttUnsubscribe);
////	mqttClient.onMessage(onMqttMessage);
////	mqttClient.onPublish(onMqttPublish);
////	mqttClient.setServer("broker.hivemq.com", 1883);
////	mqttClient.setKeepAlive(5).setClientId(mqttClientId.c_str());
////	Serial.println("[MQTT] Connecting to MQTT...");
////	mqttClient.connect();
//	mqttClient.onConnect(onMqttConnect);
//	mqttClient.onDisconnect(onMqttDisconnect);
//	mqttClient.onSubscribe(onMqttSubscribe);
//	mqttClient.onUnsubscribe(onMqttUnsubscribe);
//	mqttClient.onMessage(onMqttMessage);
//	mqttClient.onPublish(onMqttPublish);
//	mqttClient.setServer(MQTT_HOST, MQTT_PORT);
//
//}
//
