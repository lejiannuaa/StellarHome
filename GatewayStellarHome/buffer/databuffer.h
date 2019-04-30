#ifndef DATABUFFER_H
#define DATABUFFER_H

#define MAX_BUFFER_SIZE 50

#include <pthread.h>
#include <queue>
#include <string>

struct DataItem
{
    std::string topic;
    int qos;
    bool retained;
    bool dup;
    std::string payload;
};

class DataBuffer
{
private:
    //已使用缓存大小
    size_t buffer_used;
    //缓存空间
    std::queue<DataItem> buffer;
    //线程调度
    pthread_mutex_t buffer_mutex;
    pthread_cond_t buffer_not_full;
    pthread_cond_t buffer_not_empty;

public:
    DataBuffer();
    void produce_data_item(const DataItem &dataItem);
    void consume_data_item(DataItem &dataItem);
};

#endif // DATABUFFER_H
