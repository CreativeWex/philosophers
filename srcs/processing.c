#include "../includes/philosophers.h"

// void  *ft_should_philo_die(void *options)
// {
//     t_philos     *c_options;
//     int         i;
    
//     i = 0;
//     c_options = (t_args *)options;
//     while (c_options[i].f_must_die == 0)
//     {
//         i = -1;
//         while (++i < c_options->philo_number)
//         {
//             if (ft_current_time() - c_options->args->philo_arr[i].t_last_eated > c_options->t_die)
//             {
//                 c_options->f_must_die = 1;
//                 pthread_mutex_lock(&c_options->args->lock_print);
//                 printf(RED "%ld philo %d died :c", ft_time_passed(c_options->args->philo_arr[i].t_start), c_options->args->philo_arr[i].id);
// 		        pthread_mutex_unlock(&c_options->args->lock_print);
//                 return (NULL);
//             }
//         }
//             // проверка на количество приемов пищи

//     }
//     return (NULL);
// }

// void    *ft_philo_lifecycle(void* options)
// {
//     t_philos    *philo;

//     philo = (t_philos *)options;
//     philo->t_last_eated = ft_current_time();
//     while (!philo->args->f_is_dead)
//     {
//         // Условие для выхода из цикла
//         // Взять вилки
//         // Проверка
//         // Питание
//         // Проверка
//         // Сон
//         // Проверка
//         // Размышления
//         // Проверка
//         printf("Цикл пройден");
//     }
//     return (NULL);
// }