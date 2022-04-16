#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *test2(void *data)
{
    int *num = data;
    while (*num < 20)
        (*num)++;
    return 0;
}

int main()
{
    pthread_t id;
    int tmp = 0;

    pthread_create(&id, 0, test2, &tmp);
    while (tmp < 20)
        printf("%d\n", tmp);

    pthread_join(id, 0); // Ждет завершения потока, результат записывает в переменную
    return 0;
}