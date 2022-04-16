#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#typedef pthread_mutex_t t_mutex

struct t_data
{
    t_mutex *p_mutex;
    int *num;
}

void *test2(void *data)
{
    pthread_mutex_t mutex;
    int *num = data;
    while (*num < 20)
        (*num)++;
   
    return 0;
}

int main()
{
    pthread_t id;
    int tmp = 0;
    t_mutex mutex;
    t_data  data;
    data.t_mutex = mutex;
    data.num = tmp;

    pthread_mutex_init(&mutex,0);
    pthread_create(&id, 0, test2, &tmp);
    while (tmp < 20)
        printf("%d\n", tmp);

    pthread_join(id, 0); // Ждет завершения потока, результат записывает в переменную
    return 0;
}