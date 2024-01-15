#ifndef __THREAD_POOL_H_
#define __THREAD_POOL_H_

#include <pthread.h>

/* 线程池结构体 */
typedef struct threadPool_t
{
    /* 线程池中的线程 */
    pthread_t *threadId; 
    /* 最小的线程数 */
    int minThreads;
    /* 最大的线程数 */
    int maxThreads;
} threadPool_t;


#endif  //__THREAD_POOL_H_