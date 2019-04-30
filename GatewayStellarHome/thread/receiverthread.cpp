#include "receiverthread.h"

ReceiverThread::ReceiverThread(std::shared_ptr<DataBuffer> dataBuffer, std::shared_ptr<ProtocolHandler> protocolHandler) :
    dataBuffer(dataBuffer), protocolHandler(protocolHandler)
{

}

void ReceiverThread::run()
{
    protocolHandler->start_receive(dataBuffer);
}

