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

void	*dead(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;
	int stop;
	stop = 0;

	while (stop == 0)
	{
		pthread_mutex_lock(&philo->philo_arg->eating);
		if ((get_time() - philo->last_eat) >= philo->philo_arg->to_die)
		{
			pthread_mutex_unlock(&philo->philo_arg->eating);
			//death_check(philo, 1);
			print_status(philo, IS_DEAD);
			death_check(philo, 1);
			//pthread_mutex_lock(&philo->philo_arg->is_dead);
			//philo->philo_arg->stop = 1;
			//pthread_mutex_unlock(&philo->philo_arg->is_dead);
		}
		else
			pthread_mutex_unlock(&philo->philo_arg->eating);
		pthread_mutex_lock(&philo->philo_arg->is_dead);
		stop = philo->philo_arg->stop + philo->stop;
		pthread_mutex_unlock(&philo->philo_arg->is_dead);
	}
	return (NULL);
}

void	routine(t_philo *philo)
{
	int stop;

	stop = 0;

	if (philo->id_philo % 2 == 0)
        short_sleep(philo->philo_arg->to_eat / 10);
	while (!stop)
	{
		go_to_action(philo);
		if (philo->philo_arg->must_eat != -1 
			&& ++philo->times_eat == philo->philo_arg->must_eat)
		{
			pthread_mutex_lock(&philo->philo_arg->is_dead);
			philo->stop = 1;
			pthread_mutex_unlock(&philo->philo_arg->is_dead);
			return ;
		}
		think_and_sleep(philo);
		pthread_mutex_lock(&philo->philo_arg->is_dead);
		stop = philo->philo_arg->stop + philo->stop;
		pthread_mutex_unlock(&philo->philo_arg->is_dead);
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


	//printf("%lld:2\n", current_time(philo->philosophe));
	philo->argument.start_time = get_time();
	//philo->argument.start_time = 0;
	while (++i < philo->argument.number_of_philo)
	{
		//philo->philosophe[i].philo_arg = &philo->argument;
		if (philo->philosophe[i].philo_arg == NULL)
			ft_error(THREAD_ERROR);
		if (pthread_create(&philo->philosophe[i].thread, NULL, thread, &philo->philosophe[i]))
			ft_error(THREAD_ERROR);
	}
	return (1);
}
