#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *test1(void *data)
{
    printf("Hello");
    return 0;
}

int main()
{
    pthread_t id;
    void* returned;

    pthread_create(&id, 0, test1, 0);
    pthread_join(id, &returned); // Ждет завершения потока, результат записывает в переменную
    return 0;
}