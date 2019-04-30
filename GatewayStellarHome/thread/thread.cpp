#include "thread.h"
#include <pthread.h>

Thread::Thread()
{

}

int Thread::start()
{
    pthread_t thread_id;

    return(pthread_create(&thread_id, NULL, thread_start, (void *)this));
}


void Thread::run()
{

}

void *Thread::thread_start(void *arg)
{
    Thread *ptr = static_cast<Thread *>(arg);
    ptr->run();

    return NULL;
}
