#include "../includes/philosophers.h"

void  *ft_should_philo_die(void *options)
{
    t_philos     *philo;
    int         i;
    
    i = 0;
    philo = (t_philos *)options;
    while (philo[i].f_must_die == 0)
    {
        i = -1;
        while (++i < philo->philo_number)
        {
            if (ft_current_time() - philo[i].t_last_eated > philo[i].t_die)
            {
                // убить философа
                // разлочить мьютекс
                return (NULL);
            }
        }
            // проверка на количество приемов пищи

    }
    return (NULL);
}

void    *ft_philo_lifecycle(void* options)
{
    t_philos    *philo;

    philo = (t_philos *)options;
    philo->t_last_eated = ft_current_time();
    while (!philo->args->f_is_dead)
    {
        // Условие для выхода из цикла
        // Взять вилки
        // Проверка
        // Питание
        // Проверка
        // Сон
        // Проверка
        // Размышления
        // Проверка
        printf("Цикл пройден");
    }
    return (NULL);
}