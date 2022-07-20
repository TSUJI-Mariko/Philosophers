/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:12:37 by mtsuji            #+#    #+#             */
/*   Updated: 2022/07/20 12:25:38 by msuji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dead(void *arg)
{
	t_philo	*philo;
	int		stop;

	philo = (t_philo *)arg;
	stop = 0;
	while (stop == 0)
	{
		pthread_mutex_lock(&philo->philo_arg->eating);
		if (!death_check(philo, 0) && (get_time() - philo->last_eat)
			>= philo->philo_arg->to_die)
		{
			pthread_mutex_unlock(&philo->philo_arg->eating);
			print_status(philo, IS_DEAD);
			death_check(philo, 1);
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
	int	stop;

	stop = 0;
	if (philo->id_philo % 2 == 0)
		ft_usleep();
	while (!stop)
	{
		//go_to_action(philo);
		action_left(philo);
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
	return ;
}

void	*thread(void *arg)
{
	t_philo	*philo;

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
	int	i;

	philo->argument.start_time = get_time();
	if (philo->argument.number_of_philo < 100) /*jusqu'a 100 philo*/
	{
		i = -1;
		while (++i < philo->argument.number_of_philo)
		{
			if (philo->philosophe[i].philo_arg == NULL)
				ft_error(THREAD_ERROR);
			if (pthread_create(&philo->philosophe[i].thread, NULL,
					thread, &philo->philosophe[i]))
				ft_error(THREAD_ERROR);
		}
	}
	else /*plus de 100 philo*/
	{
		int j;

		i = -1;
		j = 99;
		while (++i < 100 && ++j < philo->argument.number_of_philo)
		{
			if (philo->philosophe[i].philo_arg == NULL || philo->philosophe[j].philo_arg == NULL)
				ft_error(THREAD_ERROR);
			if (pthread_create(&philo->philosophe[i].thread, NULL, thread, &philo->philosophe[i])
				|| pthread_create(&philo->philosophe[j].thread, NULL, thread, &philo->philosophe[j]))
				ft_error(THREAD_ERROR);
		}
		/*while (++j < philo->argument.number_of_philo)
		{
			if (philo->philosophe[j].philo_arg == NULL)
				ft_error(THREAD_ERROR);
			if (pthread_create(&philo->philosophe[j].thread, NULL, thread, &philo->philosophe[j]))
				ft_error(THREAD_ERROR);
		}*/

	}
	i = -1;
	while (++i < philo->argument.number_of_philo)
		pthread_join(philo->philosophe[i].thread, NULL);
	return (1);
}
