TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt




HEADERS += \
    logging.h \
    thread/thread.h \
    protocol/mqttclient/mqttpacket/MQTTConnect.h \
    protocol/mqttclient/mqttpacket/MQTTFormat.h \
    protocol/mqttclient/mqttpacket/MQTTPacket.h \
    protocol/mqttclient/mqttpacket/MQTTPublish.h \
    protocol/mqttclient/mqttpacket/MQTTSubscribe.h \
    protocol/mqttclient/mqttpacket/MQTTUnsubscribe.h \
    protocol/mqttclient/mqttpacket/StackTrace.h \
    protocol/mqttclient/FP.h \
    protocol/mqttclient/ipstack.h \
    protocol/mqttclient/MQTTClient.h \
    protocol/mqttclient/MQTTLogging.h \
    protocol/protocolhandler.h \
    protocol/mqttclienthandler.h \
    buffer/databuffer.h \
    thread/senderthread.h \
    thread/receiverthread.h \
    thread/multisenderthread.h

SOURCES += \
    main.cpp \
    thread/thread.cpp \
    protocol/mqttclient/ipstack.cpp \
    protocol/protocolhandler.cpp \
    protocol/mqttclienthandler.cpp \
    buffer/databuffer.cpp \
    thread/senderthread.cpp \
    thread/receiverthread.cpp \
    thread/multisenderthread.cpp

unix:!macx: LIBS += -lpaho-embed-mqtt3c -L../lib/x86
unix:!macx: LIBS += -lpthread
