#include <stdio.h>
#include <pthread.h>

/* 共有データ */
int NUM_THREAD = 4;
int ADD_NUM = 100000;
long long sum = 0;

/* Mutexオブジェクト */
pthread_mutex_t mutex;

/* スレッドに渡すデータ */
typedef struct thread_data {
    int addNum;
} THREAD_DATA;

void* add(void *arg)
{
    int i;
    THREAD_DATA *data;
	
	data = (THREAD_DATA*)arg;
	i = 0;
    while (i < data->addNum)
	{
        pthread_mutex_lock(&mutex);
        sum = sum + 1;
        pthread_mutex_unlock(&mutex);
		i++;
    }

    return NULL;
}

int main(void)
{
    pthread_t thread[4];
    THREAD_DATA data[4];
    int i;

    /* Mutexオブジェクトの初期化 */
    pthread_mutex_init(&mutex, NULL);
	i = 0;
    while (i < 4)
	{
        /* ADD_NUMはNUM_THREADで割り切れることを前提としている */
        data[i].addNum = 100000 / 4;
		i++;
    }

    /* スレッドの開始 */
	i = 0;
    while (i < 4)
	{
        pthread_create(&thread[i], NULL, add, &data[i]);
		i++;
    }

    /* スレッドの終了待ち */
    i = 0;
    while (i < 4)
	{
        pthread_join(thread[i], NULL);
		i++;
    }

    /* Mutexオブジェクトの破棄 */
    pthread_mutex_destroy(&mutex);

    /* 計算結果の表示 */
    printf("sum = %lld\n", sum);

    return 0;
} 