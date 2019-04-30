#ifndef MQTTCLIENTHANDLER_H
#define MQTTCLIENTHANDLER_H

#define MQTT_VESION 3
#define MQTT_HOST_NAME "localhost"
#define MQTT_HOST_PORT 1883
#define MQTT_USER_NAME "bot"
#define MQTT_PASS_WORD "123456"
#define MQTT_CLIENT_ID "voice-gateway"
#define MQTT_RECONNECT_TIME 2   //s

#define MQTT_TOPIC_NAME "Cloud to Gateway"

#include "mqttclient/ipstack.h"
#include "mqttclient/MQTTClient.h"
#include "protocolhandler.h"

class MqttClientHandler : public ProtocolHandler
{
private:
    IPStack ipstack;
    MQTT::Client<IPStack, Countdown> client;
    MQTTPacket_connectData data;
    pthread_mutex_t connect_mutex;
    //缓冲区
    static DataItem dataItemRecive;
    static DataItem dataItemSend;
    static std::shared_ptr<DataBuffer> dataBufferRecive;
    static std::shared_ptr<DataBuffer> dataBufferSend;

public:
    MqttClientHandler();
    virtual int connect();
    virtual int disconnect();
    virtual void start_receive(const std::shared_ptr<DataBuffer> &dataBuffer);
    virtual void start_send(const std::shared_ptr<DataBuffer> &dataBuffer);
    static void message_arrived(MQTT::MessageData& md);
};

#endif // MQTTCLIENTHANDLER_H
