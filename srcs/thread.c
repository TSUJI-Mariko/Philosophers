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

#include "../includes/philo.h"


void	*thread(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;		
	if (philo->id_philo % 2 == 0)
		short_sleep(philo->philo_arg->to_eat / 10);
	action(philo);
	if (philo->times_eat == philo->philo_arg->must_eat)
	{
		pthread_mutex_lock(&philo->philo_arg->finish);
		philo->philo_arg->finish_eat++;
		if (philo->philo_arg->finish_eat == philo->philo_arg->number_of_philo)
			{
				printf("every philosophers eated %d times\n", 
					philo->philo_arg->must_eat);
				pthread_mutex_unlock(&philo->philo_arg->finish);
				return (NULL);
			}
	}
	pthread_mutex_unlock(&philo->philo_arg->finish);
	return NULL;
}


void	threading(t_pa philo)
{
	int i;
	i = 0;
	
	while (i < philo.argument.number_of_philo)
	{
		philo.philosophe[i].philo_arg = &philo.argument;
		if (pthread_create(&philo.philosophe[i].thread,
			NULL, thread, &philo.philosophe[i]) == -1)
			printf("%s\n", THREAD_ERROR);
		i++;
	}
	i = 0;
	while (i < philo.argument.number_of_philo)
	{
		pthread_join(philo.philosophe[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < philo.argument.number_of_philo)
	{
		pthread_mutex_destroy(&philo.philosophe[i].left_fork);
		//pthread_mutex_destroy(&philo.philosophe[i].philo_arg->write_status);
		free(&philo.philosophe[i]);
		i++;
	}
}
