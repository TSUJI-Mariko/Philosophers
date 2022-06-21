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

#include "../includes/philo.h"

void    print_status(t_philo *philo, char *str)
{
    long int time;
    //time = -1;
    time = get_time() - philo->philo_arg->start_time;
    printf("%ld\tPhilo %d %s \n", time, philo->id_philo, str);   
}

long int    get_time(void)
{
    long int time;
    struct timeval current;

    if (gettimeofday(&current, NULL) == -1)
    {
        printf("%s\n", GET_TIME_ERROR);
        exit(1);
    }
    time = (current.tv_sec * 1000) + (current.tv_usec / 1000);
    return (time);
}

void    short_sleep(long int time)
{
    long int start;
    start = get_time();
    while ((get_time() - start) < time)
        usleep(time / 10);
}
/*
void death_or_alive(t_philo *philo)
{

}*/