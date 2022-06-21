/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:38:45 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/19 18:38:47 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    action(t_philo *philo)
{
    pthread_mutex_lock(&philo->left_fork);
    pthread_mutex_lock(&philo->philo_arg->write_status);
	print_status(philo, FORK);
    pthread_mutex_unlock(&philo->philo_arg->write_status);
    if (!philo->right_fork) // philoが1人だった場合
    {
        pthread_mutex_unlock(&philo->left_fork);
        usleep(philo->philo_arg->to_die);
        return;
    }
    pthread_mutex_lock(philo->right_fork);
    pthread_mutex_lock(&philo->philo_arg->write_status);
    print_status(philo, FORK);
    pthread_mutex_unlock(&philo->philo_arg->write_status);
    pthread_mutex_lock(&philo->philo_arg->write_status);
    pthread_mutex_lock(&philo->philo_arg->eating);
    philo->last_eat = get_time();
    print_status(philo, EATING);
    short_sleep(philo->philo_arg->to_eat);
    pthread_mutex_unlock(&philo->philo_arg->write_status);
    pthread_mutex_unlock(&philo->philo_arg->eating);
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(&philo->left_fork);
    philo->times_eat++;
    think_and_sleep(philo);
}

void    think_and_sleep(t_philo *philo)
{
    //pthread_mutex_lock(&philo->philo_arg->sleeping);
    pthread_mutex_lock(&philo->philo_arg->write_status);
    print_status(philo, SLEEPING);
    usleep(philo->philo_arg->to_sleep);
    pthread_mutex_unlock(&philo->philo_arg->write_status);
    pthread_mutex_lock(&philo->philo_arg->write_status);
    print_status(philo, THINKING);
    pthread_mutex_unlock(&philo->philo_arg->write_status);
} 