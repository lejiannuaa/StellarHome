#ifndef THREAD_H
#define THREAD_H


class Thread
{
public:
    Thread();
    //启动线程
    int start();
    virtual void run();

private:
    static void *thread_start(void *);
};

#endif // THREAD_H
