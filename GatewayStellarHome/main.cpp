/*
#define MQTTCLIENT_QOS2 1

#include <memory.h>

#include "protocol/mqttclient/MQTTClient.h"

#define DEFAULT_STACK_SIZE -1

#include "protocol/mqttclient/ipstack.h"
#include "pthread.h"
#include <unistd.h>
#include "logging.h"
#include "protocol/mqttclienthandler.h"
#include <memory>




int arrivedcount = 0;
const char* topic = "topic"; //mbed-sample

void messageArrived(MQTT::MessageData& md)
{
    printf("=========messageArrived : %u\n",pthread_self());
    MQTT::Message &message = md.message;

    printf("Message %d arrived: qos %d, retained %d, dup %d, packetid %d\n",
        ++arrivedcount, message.qos, message.retained, message.dup, message.id);
    printf("Topic %.*s\n", (int)md.topicName.lenstring.len, md.topicName.lenstring.data);
    printf("Payload %.*s\n", (int)message.payloadlen, (char*)message.payload);
}

void messageArrived2(MQTT::MessageData& md)
{
    printf("=========messageArrived : %u\n",pthread_self());
    MQTT::Message &message = md.message;

    printf("Message %d arrived: qos %d, retained %d, dup %d, packetid %d\n",
        ++arrivedcount, message.qos, message.retained, message.dup, message.id);
    printf("Topic %.*s\n", (int)md.topicName.lenstring.len, md.topicName.lenstring.data);
    printf("Payload %.*s\n", (int)message.payloadlen, (char*)message.payload);
}

void * thread_fun(void *arg)
{
    MQTT::Client<IPStack, Countdown> *client = (MQTT::Client<IPStack, Countdown> *)arg;
    int rc = client->subscribe(topic, MQTT::QOS2, messageArrived);
    printf("=========thread: %u\n",pthread_self());
    if (rc != 0)
        printf("rc from MQTT subscribe is %d\n", rc);

    for(int i=0;i<5;i++)
//    while(1)
    {
        printf("=========thread: %u\n",pthread_self());
        client->yield(1000);
    }
    rc = client->subscribe("topic 2", MQTT::QOS2, messageArrived2);
    while(1)
    {
        printf("=========thread: %u\n",pthread_self());
        client->yield(1000);
    }
}

void * thread_fun2(void *arg)
{
    MQTT::Client<IPStack, Countdown> *client = (MQTT::Client<IPStack, Countdown> *)arg;
    int rc = client->subscribe("topic 2", MQTT::QOS2, messageArrived2);
    printf("=========thread 2: %u\n",pthread_self());
    if (rc != 0)
        printf("rc from MQTT subscribe is %d\n", rc);

}
*/

#include "memory"
#include "buffer/databuffer.h"
#include "protocol/mqttclienthandler.h"
#include "thread/receiverthread.h"
#include "thread/senderthread.h"

int main(int argc, char* argv[])
{
    std::shared_ptr<DataBuffer> dataBufferUpstream = std::make_shared<DataBuffer>();
    std::shared_ptr<DataBuffer> dataBufferDownstream = std::make_shared<DataBuffer>();
    std::shared_ptr<ProtocolHandler> protocolHandler = std::make_shared<MqttClientHandler>();
    std::shared_ptr<ReceiverThread> receiverThread =
            std::make_shared<ReceiverThread>(dataBufferUpstream, protocolHandler);
    std::shared_ptr<SenderThread> senderThread =
            std::make_shared<SenderThread>(dataBufferUpstream, protocolHandler);

    receiverThread->start();
    senderThread->start();

    pause();
//    std::shared_ptr<ProtocolHandler> protocolHandler(new MqttClientHandler);

    /*
    printf("=========main : %u\n",pthread_self());
    IPStack ipstack = IPStack();
    float version = 0.3;
    const char* topic = "topic"; //mbed-sample

    printf("Version is %f\n", version);

    MQTT::Client<IPStack, Countdown> client = MQTT::Client<IPStack, Countdown>(ipstack);

//    const char* hostname = "m2m.eclipse.org";
    const char* hostname = "localhost";
    int port = 1883;
    printf("Connecting to %s:%d\n", hostname, port);
    int rc = ipstack.connect(hostname, port);
    if (rc != 0)
        printf("rc from TCP connect is %d\n", rc);

    printf("MQTT connecting\n");
    MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
    data.MQTTVersion = 3;
    data.clientID.cstring = (char*)"mbed-icraggs";
    data.username.cstring = (char*)"bot";
    data.password.cstring = (char*)"123456";
    rc = client.connect(data);
    if (rc != 0)
        printf("rc from MQTT connect is %d\n", rc);
    printf("MQTT connected\n");

    pthread_t thread_id;
    pthread_t thread_id2;
    pthread_create(&thread_id, NULL, &thread_fun, &client);

    MQTT::Message message;

    // QoS 0
    char buf[100];
    sprintf(buf, "Hello World!  QoS 0 message from app version %f", version);
    message.qos = MQTT::QOS0;
    message.retained = false;
    message.dup = false;
    message.payload = (void*)buf;
    message.payloadlen = strlen(buf)+1;
    DEBUG("QS0\n")
    printf("QS0\n", rc);
    while(1)
    {
        sleep(2);
        rc = client.publish(topic, message);
        if (rc != 0)
            printf("Error %d from sending QoS 0 message\n", rc);
        rc = client.publish("topic 2", message);
        if (rc != 0)
            printf("Error %d from sending QoS 0 message\n", rc);
    }

    sleep(10);

    */
    return 0;
}

