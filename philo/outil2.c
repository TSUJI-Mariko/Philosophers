/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:25:21 by mtsuji            #+#    #+#             */
/*   Updated: 2022/07/24 22:43:39 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	long long		time;
	struct timeval	current;

	time = 0;
	if (gettimeofday(&current, NULL) == -1)
		return (printf("%s\n", GET_TIME_ERROR));
	time = (current.tv_sec * 1000) + (current.tv_usec / 1000);
	return (time);
}

long long	current_time(t_philo *philo)
{
	long long	time;

	time = (get_time() - philo->philo_arg->start_time);
	return (time);
}

/*void	short_sleep(long int time)
{
	long int	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
}*/

void	short_sleep(long int time, t_philo *philo)
{
	long int	start;

	start = get_time();
	while (death_check(philo, 0) == 0)
	{
		if ((get_time() - start) >= time)
			break ;
		usleep(100);
	}
}

int	death_check(t_philo *philo, int dead)
{
	pthread_mutex_lock(&philo->philo_arg->is_dead);
	if (dead == 1)
		philo->philo_arg->stop = dead;
	if (philo->philo_arg->stop == 1)
	{
		pthread_mutex_unlock(&philo->philo_arg->is_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->philo_arg->is_dead);
	return (0);
}

int	ft_error(char *str, t_philo *philo)
{
	printf("%s\n", str);
	free(philo);
	exit(1);
}
