#ifndef PRODUCEDATATHREAD_H
#define PRODUCEDATATHREAD_H

#include "thread.h"
#include <memory>
#include "../buffer/databuffer.h"
#include "../protocol/protocolhandler.h"

class SenderThread : public Thread
{
private:
    //接收缓冲区
    const std::shared_ptr<DataBuffer> dataBuffer;
    //通信方式
    const std::shared_ptr<ProtocolHandler> protocolHandler;

public:
    SenderThread(std::shared_ptr<DataBuffer> dataBuffer, std::shared_ptr<ProtocolHandler> protocolHandler);
    virtual void run();
};

#endif // PRODUCEDATATHREAD_H
