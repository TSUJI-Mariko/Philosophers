/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:38:45 by mtsuji            #+#    #+#             */
/*   Updated: 2022/07/24 22:43:17 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think_and_sleep(t_philo *philo)
{
	print_status(philo, SLEEPING);
	short_sleep(philo->philo_arg->to_sleep, philo);
	print_status(philo, THINKING);
}

void	action_left(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	print_status(philo, FORK);
	if (!philo->right_fork)
	{
		pthread_mutex_unlock(&philo->left_fork);
		short_sleep(philo->philo_arg->to_die, philo);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, FORK);
	pthread_mutex_lock(&philo->philo_arg->eating);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->philo_arg->eating);
	print_status(philo, EATING);
	short_sleep(philo->philo_arg->to_eat, philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

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

void	go_to_action(t_philo *philo)
{
	if (philo->id_philo % 2)
		action_left(philo);
	else
		action_right(philo);
}
