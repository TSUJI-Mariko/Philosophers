/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:25:21 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/18 17:25:23 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_status(t_philo *philo, char *str)
{
    //long int time;
    //time = -1;
    //time = current_time(philo);
    pthread_mutex_lock(&philo->philo_arg->is_dead);
    if (philo->philo_arg->stop == 1)
    {
        pthread_mutex_unlock(&philo->philo_arg->is_dead);
        return ;
    }
    //pthread_mutex_unlock(&philo->philo_arg->is_dead);  
    if (current_time(philo) >= 0 && philo->philo_arg->stop == 0)
    {
        pthread_mutex_lock(&philo->philo_arg->write_status);
        //time = get_time() - philo->philo_arg->start_time;
        printf("%lld\t", current_time(philo)); 
        printf("Philo %d %s \n", philo->id_philo, str); 
        pthread_mutex_unlock(&philo->philo_arg->write_status);
    } 
    pthread_mutex_unlock(&philo->philo_arg->is_dead); 
}

long long    get_time(void)
{
    long long time;
    struct timeval current;

    time = 0;
    if (gettimeofday(&current, NULL) == -1)
        return (printf("%s\n", GET_TIME_ERROR));
    time = (current.tv_sec * 1000) + (current.tv_usec / 1000);
    return (time);
}

long long current_time(t_philo *philo)
{
    long long time;
    time = (get_time() - philo->philo_arg->start_time);
    return (time);
}

void    short_sleep(long int time)
{
    long int start;
    start = get_time();
    while ((get_time() - start) < time)
        usleep(time / 10);
} 

void death_check(t_philo *philo, int dead)
{
    pthread_mutex_lock(&philo->philo_arg->is_dead);
    if (dead == 1)
        philo->philo_arg->stop = dead;
    if (philo->philo_arg->stop == 1)
    {
        pthread_mutex_unlock(&philo->philo_arg->is_dead);
        return;
    }
	pthread_mutex_unlock(&philo->philo_arg->is_dead);
    return;
}

int ft_error(char *str)
{
    printf("%s\n",str);
    exit(1);
}