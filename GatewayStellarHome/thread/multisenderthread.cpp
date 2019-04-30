#include "multisenderthread.h"

MultiSenderThread::MultiSenderThread(std::shared_ptr<DataBuffer> dataBuffer, std::vector<std::shared_ptr<ProtocolHandler>> protocolHandlerArray) :
    dataBuffer(dataBuffer), protocolHandlerArray(protocolHandlerArray)
{

}

