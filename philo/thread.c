/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:12:37 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/14 14:54:39 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//とりあえず動作するバージョン
/*
void	*dead(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;
	//long long time;

	//time = get_time();

	pthread_mutex_lock(&philo->philo_arg->eating);
	if (!death_check(philo, 0) && 
		(get_time() - philo->last_eat) >= philo->philo_arg->to_die)
	{
		pthread_mutex_unlock(&philo->philo_arg->eating);
		print_status(philo, IS_DEAD);
		death_check(philo, 1);
	}
	else
		pthread_mutex_unlock(&philo->philo_arg->eating);
	return (NULL);
}


void	*dead(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;
	long long time;

	time = get_time();

	pthread_mutex_lock(&philo->philo_arg->eating);
	if (!death_check(philo, 0) && 
		(time - philo->last_eat) >= philo->philo_arg->to_die)
	{
		pthread_mutex_unlock(&philo->philo_arg->eating);
		print_status(philo, IS_DEAD);
		death_check(philo, 1);
	}
	else
		pthread_mutex_unlock(&philo->philo_arg->eating);
	return (NULL);
}*/

void	*dead(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;
	int stop;
	stop = 0;
	//long long time;

	//time = get_time();
	//pthread_mutex_lock(&philo->philo_arg->finish);
	while (stop == 0)
	{
		pthread_mutex_lock(&philo->philo_arg->eating);
		if ((get_time() - philo->last_eat) >= philo->philo_arg->to_die)
		{
			pthread_mutex_unlock(&philo->philo_arg->eating);
			//pthread_mutex_unlock(&philo->philo_arg->finish);
			print_status(philo, IS_DEAD);
			death_check(philo, 1);
		}
		else
		{
			pthread_mutex_unlock(&philo->philo_arg->eating);
			//pthread_mutex_unlock(&philo->philo_arg->finish);
		}
		pthread_mutex_lock(&philo->philo_arg->is_dead);
		stop = philo->philo_arg->stop;
		pthread_mutex_unlock(&philo->philo_arg->is_dead);
	}
	return (NULL);
}

void	routine(t_philo *philo)
{
	while (death_check(philo, 0) == 0)
	{
		go_to_action(philo);
		if (++philo->times_eat == philo->philo_arg->must_eat)
		{/*
			pthread_mutex_lock(&philo->philo_arg->finish);
			philo->stop_eat = 1;
			philo->philo_arg->finish_eat++;
			if (philo->philo_arg->finish_eat == philo->philo_arg->number_of_philo)
			{
				pthread_mutex_unlock(&philo->philo_arg->finish);
				death_check(philo, 2);
			}
			else
				pthread_mutex_unlock(&philo->philo_arg->finish);
			return;*/
			//pthread_mutex_lock(&philo->philo_arg->finish);
			//philo->stop_eat = 1;
			//pthread_mutex_unlock(&philo->philo_arg->finish);
			death_check(philo, 1);
			return ;
		}
		think_and_sleep(philo);
	}
	return;
}

void	*thread(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;	

	philo->last_eat = philo->philo_arg->start_time;
	if (pthread_create(&philo->dead, NULL, &dead, philo))
		return (NULL);
	routine(philo);
	pthread_detach(philo->dead);
	return (NULL);
}


int	thread_start(t_pa *philo)
{
	int i;
	i = -1;
	//philo->argument.start_time = get_time();
	//philo->argument.start_time = 0;
	while (++i < philo->argument.number_of_philo)
	{
		philo->philosophe[i].philo_arg = &philo->argument;
		if (philo->philosophe[i].philo_arg == NULL)
			ft_error(THREAD_ERROR);
		if (pthread_create(&philo->philosophe[i].thread, NULL, thread, &philo->philosophe[i]) != 0)
			ft_error(THREAD_ERROR);
	}
	return (1);
}
