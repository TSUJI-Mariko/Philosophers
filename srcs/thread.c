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

/*void	*dead(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;
	//pthread_mutex_lock(&philo->philo_arg->finish);
	short_sleep(philo->philo_arg->to_die);
	pthread_mutex_lock(&philo->philo_arg->eating);
	//if (stopper(0, philo) && (get_time() - philo->last_eat) >= (long)(philo->philo_arg->to_die))
	if ((get_time() - philo->last_eat) >= (long)(philo->philo_arg->to_die))
	{
		//pthread_mutex_lock(&philo->philo_arg->is_dead);
		//pthread_mutex_unlock(&philo->philo_arg->is_dead);
		pthread_mutex_unlock(&philo->philo_arg->eating);
		pthread_mutex_lock(&philo->philo_arg->is_dead);
		philo->philo_arg->stop = 1;
		pthread_mutex_unlock(&philo->philo_arg->is_dead);
		//pthread_mutex_unlock(&philo->philo_arg->eating);
		//pthread_mutex_unlock(&philo->philo_arg->finish);
		pthread_mutex_lock(&philo->philo_arg->write_status);
		print_status(philo, IS_DEAD);
		pthread_mutex_unlock(&philo->philo_arg->write_status);
		//stopper(1, philo);
	}
	//pthread_mutex_unlock(&philo->philo_arg->finish);
	pthread_mutex_unlock(&philo->philo_arg->eating);
	return NULL;
}*/
/*
void	routine(t_philo *philo)
{
	//int stop;
	//stop = 0;
	if (philo->id_philo % 2 == 0)
		short_sleep(philo->philo_arg->to_eat / 10);
	action(philo);
	if (philo->times_eat == philo->philo_arg->must_eat)
	{
		pthread_mutex_lock(&philo->philo_arg->finish);
		philo->philo_arg->finish_eat++;
		if (philo->philo_arg->finish_eat == philo->philo_arg->number_of_philo)
			{
				//printf("every philosophers eated %d times\n", 
				//philo->philo_arg->must_eat);
				pthread_mutex_unlock(&philo->philo_arg->finish);
				//stopper(1, philo);
				//pthread_mutex_lock(&philo->philo_arg->is_dead);
				//stop = 1;
				//pthread_mutex_unlock(&philo->philo_arg->is_dead);
				return;
			}
		pthread_mutex_unlock(&philo->philo_arg->finish);
		return;
	}
	think_and_sleep(philo);
}*/
/*
void	*dead(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;
	short_sleep(philo->philo_arg->to_die);
	pthread_mutex_lock(&philo->philo_arg->eating);
	//if (stopper(0, philo) && (get_time() - philo->last_eat) >= (long)(philo->philo_arg->to_die))
	if ((get_time() - philo->last_eat) >= (long)(philo->philo_arg->to_die))
	{
		pthread_mutex_unlock(&philo->philo_arg->eating);
		pthread_mutex_lock(&philo->philo_arg->is_dead);
		philo->philo_arg->stop = 1;
		pthread_mutex_unlock(&philo->philo_arg->is_dead);
		//pthread_mutex_lock(&philo->philo_arg->write_status);
		print_status(philo, IS_DEAD);
		//pthread_mutex_unlock(&philo->philo_arg->write_status);
	}
	else
		pthread_mutex_unlock(&philo->philo_arg->eating);
	return NULL;
}
*/
/*
void	routine(t_philo *philo)
{
	int stop;

	stop = 0;
	while (!stop)
	{
		go_to_action(philo);
		if (philo->times_eat == philo->philo_arg->must_eat)
		{
			pthread_mutex_lock(&philo->philo_arg->finish);
			philo->philo_arg->finish_eat++;
			if (philo->philo_arg->finish_eat == philo->philo_arg->number_of_philo)
			{
				pthread_mutex_unlock(&philo->philo_arg->finish);
				pthread_mutex_lock(&philo->philo_arg->is_dead);
				philo->philo_arg->stop = 1;
				pthread_mutex_unlock(&philo->philo_arg->is_dead);
				return;
			}
			pthread_mutex_unlock(&philo->philo_arg->finish);
		}
		think_and_sleep(philo);
		pthread_mutex_lock(&philo->philo_arg->is_dead);
		stop = philo->philo_arg->stop;
		pthread_mutex_unlock(&philo->philo_arg->is_dead);
	}
	return;
}*/

void	*dead(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;
	long long time;
	int stop;

	stop = 0;
	time = get_time();
	//while (!death_check(philo, 0))
	while (!stop)
	{
		pthread_mutex_lock(&philo->philo_arg->eating);
		//if (stopper(0, philo) && (get_time() - philo->last_eat) >= (long)(philo->philo_arg->to_die))
		if ((time - philo->last_eat) >= philo->philo_arg->to_die)
		{
			pthread_mutex_unlock(&philo->philo_arg->eating);
			pthread_mutex_lock(&philo->philo_arg->is_dead);
			philo->stop = 1;
			pthread_mutex_unlock(&philo->philo_arg->is_dead);
			//death_check(philo, 2);
			print_status(philo, IS_DEAD);
			//return (NULL);
		}
		else
			pthread_mutex_unlock(&philo->philo_arg->eating);
		pthread_mutex_lock(&philo->philo_arg->is_dead);
		stop = philo->stop + philo->philo_arg->stop;
		pthread_mutex_unlock(&philo->philo_arg->is_dead);
	}
	return (NULL);
}
/*
void	routine(t_philo *philo)
{
	int stop;

	stop = 0;
	while (!stop)
	{
		go_to_action(philo);
		
		//pthread_mutex_lock(&philo->philo_arg->eating);
		if (philo->times_eat == philo->philo_arg->must_eat)
		{
			//pthread_mutex_unlock(&philo->philo_arg->eating);
			pthread_mutex_lock(&philo->philo_arg->is_dead);
			philo->stop = 1;
			pthread_mutex_unlock(&philo->philo_arg->is_dead);
			return;
		}
		//pthread_mutex_unlock(&philo->philo_arg->eating);
		think_and_sleep(philo);
		pthread_mutex_lock(&philo->philo_arg->is_dead);
		stop = philo->stop + philo->philo_arg->stop;
		pthread_mutex_unlock(&philo->philo_arg->is_dead);
	}
	return;
}*/

void	*thread(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;	
	//死んだ時の処理を入れなければならない
	philo->last_eat = philo->philo_arg->start_time;
	int stop;

	stop = 0;
	//while (!death_check(philo, 0))
	while (!stop)
	{
		pthread_create(&philo->dead, NULL, &dead, arg);
		go_to_action(philo);
		pthread_detach(philo->dead);
		pthread_mutex_lock(&philo->philo_arg->eating);
		if (philo->times_eat == philo->philo_arg->must_eat)
		{
			pthread_mutex_unlock(&philo->philo_arg->eating);
			pthread_mutex_lock(&philo->philo_arg->is_dead);
			philo->stop = 1;
			pthread_mutex_unlock(&philo->philo_arg->is_dead);
			//death_check(philo, 2);
			return NULL;
		}
		else
			pthread_mutex_unlock(&philo->philo_arg->eating);
		think_and_sleep(philo);
		pthread_mutex_lock(&philo->philo_arg->is_dead);
		stop = philo->stop + philo->philo_arg->stop;
		pthread_mutex_unlock(&philo->philo_arg->is_dead);
	}
	return NULL;
}


int	thread_start(t_pa *philo)
{
	int i;
	i = -1;
	philo->argument.start_time = get_time();
	while (++i < philo->argument.number_of_philo)
	{
		philo->philosophe[i].philo_arg = &philo->argument;
		if (pthread_create(&philo->philosophe[i].thread,
			NULL, thread, &philo->philosophe[i]) == -1)
			return (printf("%s\n", THREAD_ERROR));
	}
	i = -1;
	while (++i < philo->argument.number_of_philo)
		pthread_join(philo->philosophe[i].thread, NULL);
	return (1);
}
