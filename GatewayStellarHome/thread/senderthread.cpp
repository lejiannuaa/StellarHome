#include "senderthread.h"

SenderThread::SenderThread(std::shared_ptr<DataBuffer> dataBuffer, std::shared_ptr<ProtocolHandler> protocolHandler) :
    dataBuffer(dataBuffer), protocolHandler(protocolHandler)
{

}

void SenderThread::run()
{
    protocolHandler->start_send(dataBuffer);
}
