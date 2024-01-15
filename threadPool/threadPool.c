#include <stdlib.h>
#include <string.h>
#include "threadPool.h"

#define DEFAULT_MIN_THREADS 5
#define DEFAULT_MAX_THREADS 10

/* 状态码 */
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
    UNKONWN_ERROR
};

void *threadHander(void *arg)
{

    pthread_exit(NULL);
}

/* 线程池初始化 */
int threadPoolInit(threadPool_t *pool, int minThreads, int maxThreads)
{
    if (!pool)
    {
        return NULL_PTR;
    }
    do
    {
        /* 判断合法性 */
        if (minThreads < 0 || maxThreads < 0 || minThreads > maxThreads)
        {
            minThreads = DEFAULT_MIN_THREADS;
            maxThreads = DEFAULT_MAX_THREADS;
        }

        /* 更新线程池属性 */
        pool->minThreads = minThreads;
        pool->maxThreads = maxThreads;

        pool->threadIds = (pthread_t)malloc(sizeof(pthread_t) * maxThreads);
        if (!pool->threadIds)
        {
            perror("malloc error");
            break;
        }
        /* 清除脏数据 */
        memset(pool->threadIds, 0, sizeof(pool->threadIds));

        int ret = 0;
        /* 创建线程 */
        for (int idx = 0; idx < pool->minThreads; idx++)
        {
            /* 如果线程ID号为0，那么这个位置可以用 */
            if (pool->threadIds[idx] == 0)
            {
                ret = pthread_create(&(pool->threadIds[idx]), NULL, threadHander, NULL);
                if (ret != 0)
                {
                    perror("thread create error");
                    break;
                }
            }
        }

        return ON_SUCCESS;
    } while(0);

    /* 程序执行到这个地方， 上面一定有失败 */
    if (!pool->threadIds)
    {
        free(pool->threadIds);
        pool->threadIds = NULL;
        return UNKONWN_ERROR;
    }

    /* 回收线程资源 */
    for (int idx = 0; idx < pool->minThreads; idx++)
    {
        if (pool->threadIds[idx] != 0)
        {
            pthread_join(pool->threadIds[idx], NULL);
        }
    }

    return ON_SUCCESS;
}

/* 线程池销毁 */
int threadPoolDestory(threadPool_t *pool)
{

    return ON_SUCCESS;
}