# Потоки

**Поток** - абстракция, последовательно выполняющая команды. При многопоточности команды выполняются параллельно. Каждый поток в рамках процесса имеет свой уникальный id.


# Создание потоков
Новый поток создаётся с помощью функции pthread_create
```
int pthread_create(*ptherad_t, const pthread_attr_t *attr, void* (*start_routine)(void*), void *arg);
```

```
int pthread_create(id_потока, NULL_для_свойств_по_умолчанию, функция, аргументы_для_функции);
```
Функция получает в качестве аргументов указатель на поток, переменную типа pthread_t, в которую, в случае удачного завершения сохраняет id потока. pthread_attr_t – атрибуты потока. В случае если используются атрибуты по умолчанию, то можно передавать NULL. start_routin – это непосредственно та функция, которая будет выполняться в новом потоке. arg – это аргументы, которые будут переданы функции.

Поток может выполнять много разных дел и получать разные аргументы. Для этого функция, которая будет запущена в новом потоке, принимает аргумент типа void*. За счёт этого можно обернуть все передаваемые аргументы в структуру. Возвращать значение можно также через передаваемый аргумент.

# Ожидание завершения потока | Возврат ресурсов потока

`int pthread_join(thread_t tid, void **status);` - в текущем потоке ожидает завершения потока, переданного в качестве параметра. Второй аргумент - переменная для записи результата работы функции (&result). 

`int pthread_detach(pthread_t thread);` - отсоединение потока для автономной фоновой работы. Используется для возврата ресурсов при отсутствии необходимости ждать завершения потока.

join и detach используются для возврата ресурсов потоков. Поток нельзя одновременно join и detach.

# Примитивы синхронизации

**Мьютексы** — это простейшие двоичные семафоры, которые могут находиться в одном из двух состояний — отмеченном или неотмеченном (открыт и закрыт соответственно). Задача мьютекса — защита объекта от доступа к нему других потоков, отличных от того, который завладел мьютексом. В каждый конкретный момент только один поток может владеть объектом, защищённым мьютексом. Если другому потоку будет нужен доступ к переменной, защищённой мьютексом, то этот поток блокируется до тех пор, пока мьютекс не будет освобождён.

Цель использования мьютексов — защита данных от повреждения в результате асинхронных изменений (состояние гонки - поток считывает переменную, изменяющуюся в другом потоке), однако могут порождаться другие проблемы (например взаимные блокировки).

# Дедлок    

**Дедлок** – состояние взаимной блокировки двух или более потоков. Такая ситуация возникает в том случае, когда первый поток ждёт освобождения ресурса, которым владеет второй поток, а второй поток ждёт освобождения ресурса, которым владеет первый. Понятно, что в таком состоянии могут находиться не только два потока, а несколько.