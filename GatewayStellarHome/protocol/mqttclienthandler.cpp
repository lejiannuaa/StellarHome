#include "mqttclienthandler.h"
#include "../logging.h"

DataItem MqttClientHandler::dataItemRecive = {"topic", 0, false, false, "payload"};
DataItem MqttClientHandler::dataItemSend = {"topic", 0, false, false, "payload"};
std::shared_ptr<DataBuffer> MqttClientHandler::dataBufferRecive = std::make_shared<DataBuffer>();
std::shared_ptr<DataBuffer> MqttClientHandler::dataBufferSend = std::make_shared<DataBuffer>();

MqttClientHandler::MqttClientHandler() : client(ipstack), data(MQTTPacket_connectData_initializer)
{
    data.MQTTVersion = MQTT_VESION;
    data.username.cstring = MQTT_USER_NAME;
    data.password.cstring = MQTT_PASS_WORD;
    data.clientID.cstring = MQTT_CLIENT_ID;
//    data.MQTTPacket_willOptions = //遗愿
    //必须设置，否则isConnected监测不到连接情况
    data.keepAliveInterval = 3;

    connect();
}

int MqttClientHandler::connect()
{
    if(!client.isConnected())
    {
        int rc = -1;
        while(rc)
        {
            rc = ipstack.connect(MQTT_HOST_NAME, MQTT_HOST_PORT);
            if(!rc)
            {
                rc = client.connect(data);
            }
            if(rc)
            {
                sleep(MQTT_RECONNECT_TIME);
            }
        }
    }
}

int MqttClientHandler::disconnect()
{
    int rc = client.disconnect();
    if (rc != 0)
    {
        return rc;
    }

    rc = ipstack.disconnect();
    return rc;
}

void MqttClientHandler::message_arrived(MQTT::MessageData& md)
{
    MQTT::Message &message = md.message;
    dataItemRecive.topic = static_cast<char *>(md.topicName.lenstring.data);
    dataItemRecive.qos = message.qos;
    dataItemRecive.retained = message.retained;
    dataItemRecive.dup = message.dup;
    dataItemRecive.payload = static_cast<char *>(message.payload);

    dataBufferRecive->produce_data_item(dataItemRecive);
    DEBUG("message_arrived ========= thread id : %u\n",pthread_self());
    DEBUG("Topic: %.*s, Payload: %.*s\n", (int)md.topicName.lenstring.len,
          md.topicName.lenstring.data, (int)message.payloadlen, (char*)message.payload);
}

void MqttClientHandler::start_receive(const std::shared_ptr<DataBuffer> &dataBuffer)
{
    dataBufferRecive = dataBuffer;

    while(1)
    {
        if(!client.subscribe(MQTT_TOPIC_NAME, MQTT::QOS0, message_arrived))
        {
            while(1)
            {
                //阻塞等待数据
                client.yield(100);

                if(!client.isConnected())
                {
                    DEBUG("lose connect ========= thread id : %u\n",pthread_self());
                    break;
                }
            }
        }

        connect();
    }
}

void MqttClientHandler::start_send(const std::shared_ptr<DataBuffer> &dataBuffer)
{
    dataBufferRecive = dataBuffer;

    while(1)
    {
        dataBufferRecive->consume_data_item(dataItemSend);

        MQTT::Message message;
        message.qos = static_cast<MQTT::QoS>(dataItemSend.qos);
        message.retained = dataItemSend.retained;
        message.dup = dataItemSend.dup;
        message.payloadlen = dataItemSend.payload.length()+1;
        message.payload = const_cast<char *>(dataItemSend.payload.data());

//        client.publish(dataItemSend.topic.data(), message);
        client.publish("Gateway to Equipment", message);
    }
}

