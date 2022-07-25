/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:38:45 by mtsuji            #+#    #+#             */
/*   Updated: 2022/07/24 23:03:22 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think_and_sleep(t_philo *philo)
{
	print_status(philo, SLEEPING);
	short_sleep(philo->philo_arg->to_sleep, philo);
	print_status(philo, THINKING);
	ft_usleep(philo);
}

int	take_fork(t_philo *philo)
{
	if (philo->id_philo % 2 == 1)
	{
		pthread_mutex_lock(&philo->left_fork);
		print_status(philo, FORK);
		if (!philo->right_fork)
		{
			pthread_mutex_unlock(&philo->left_fork);
			short_sleep(philo->philo_arg->to_die, philo);
			return (0);
		}
	}
	pthread_mutex_lock(philo->right_fork);
	if (philo->id_philo % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_fork);
		print_status(philo, FORK);
	}
	print_status(philo, FORK);
	return (1);
}

void	eating(t_philo *philo)
{
	if (take_fork(philo) == 0)
		return ;
	pthread_mutex_lock(&philo->philo_arg->eating);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->philo_arg->eating);
	print_status(philo, EATING);
	short_sleep(philo->philo_arg->to_eat, philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

/*
void	action_right(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, FORK);
	pthread_mutex_lock(&philo->left_fork);
	print_status(philo, FORK);
	pthread_mutex_lock(&philo->philo_arg->eating);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->philo_arg->eating);
	print_status(philo, EATING);
	short_sleep(philo->philo_arg->to_eat, philo);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
*/