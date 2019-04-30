#ifndef MULTIPRODUCEDATATHREAD_H
#define MULTIPRODUCEDATATHREAD_H

#define MAX_PROTOCOL_COUNTS 6

#include "thread.h"
#include <memory>
#include <vector>
#include "../buffer/databuffer.h"
#include "../protocol/protocolhandler.h"

class MultiSenderThread : public Thread
{
private:
    //发送缓冲区
    const std::shared_ptr<DataBuffer> dataBuffer;
    //通信方式
    const std::vector<std::shared_ptr<ProtocolHandler>> protocolHandlerArray;

public:
    MultiSenderThread(std::shared_ptr<DataBuffer> dataBuffer, std::vector<std::shared_ptr<ProtocolHandler>> protocolHandlerArray);
};

#endif // MULTIPRODUCEDATATHREAD_H
