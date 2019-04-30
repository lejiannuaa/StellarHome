#ifndef PROTOCOLHANDLER_H
#define PROTOCOLHANDLER_H

#include <memory>
#include "../buffer/databuffer.h"


class ProtocolHandler
{
public:
    ProtocolHandler();
    virtual int connect();
    virtual int disconnect();
    virtual void start_receive(const std::shared_ptr<DataBuffer> &dataBuffer);
    virtual void start_send(const std::shared_ptr<DataBuffer> &dataBuffer);
};

#endif // PROTOCOLHANDLER_H
