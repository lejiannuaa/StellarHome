#include "databuffer.h"


DataBuffer::DataBuffer() :
    buffer_used(0), buffer_mutex(PTHREAD_MUTEX_INITIALIZER),
    buffer_not_full(PTHREAD_COND_INITIALIZER), buffer_not_empty(PTHREAD_COND_INITIALIZER)
{

}

void DataBuffer::produce_data_item(const DataItem &dataItem)
{
    pthread_mutex_lock(&buffer_mutex);

    //检查缓存剩余空间
    if(buffer_used >= MAX_BUFFER_SIZE)
    {
        //线程调度 等待非满条件
        pthread_cond_wait(&buffer_not_full, &buffer_mutex);
    }
    //写入缓存
    buffer.push(dataItem);
    buffer_used++;
    //线程调度 通知非空条件
    pthread_cond_signal(&buffer_not_empty);

    pthread_mutex_unlock(&buffer_mutex);
}

void DataBuffer::consume_data_item(DataItem &dataItem)
{
    pthread_mutex_lock(&buffer_mutex);

    //检查缓存剩余空间
    if(buffer_used <= 0)
    {
        //线程调度 等待非空条件
        pthread_cond_wait(&buffer_not_empty, &buffer_mutex);
    }
    //读取缓存
    dataItem = buffer.front();
    buffer.pop();
    buffer_used--;
    //线程调度 通知非满条件
    pthread_cond_signal(&buffer_not_full);

    pthread_mutex_unlock(&buffer_mutex);
}

