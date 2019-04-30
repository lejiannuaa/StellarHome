#ifndef CONSUMEDATATHREAD_H
#define CONSUMEDATATHREAD_H

#include "thread.h"
#include <memory>
#include "../buffer/databuffer.h"
#include "../protocol/protocolhandler.h"

class ReceiverThread : public Thread
{
private:
    //接收缓冲区
    const std::shared_ptr<DataBuffer> dataBuffer;
    //通信方式
    const std::shared_ptr<ProtocolHandler> protocolHandler;

public:
    ReceiverThread(std::shared_ptr<DataBuffer> dataBuffer, std::shared_ptr<ProtocolHandler> protocolHandler);
    virtual void run();
};

#endif // CONSUMEDATATHREAD_H
