/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:28:56 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/14 15:03:14 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void cleanup_table(t_pa *philo, t_arg *arg)
{
	int i;
	i = -1;

	while (++i < arg->number_of_philo)
		pthread_join(philo->philosophe[i].thread, NULL);
	//pthread_mutex_destroy(&arg->meal_check);
    pthread_mutex_destroy(&arg->finish);
    pthread_mutex_destroy(&arg->eating);
    pthread_mutex_destroy(&arg->is_dead);
	pthread_mutex_destroy(&arg->write_status);
	i = -1;
	while (++i < arg->number_of_philo)
		pthread_mutex_destroy(&philo->philosophe[i].left_fork);
	if (arg->stop == 2)
		printf("%lld\tevery philosophers eated %d times\n", get_time() - arg->start_time, arg->must_eat);
	free(philo->philosophe);
}


int	main(int argc, char **argv)
{
	t_pa philo;

	
	if (!spread_argument(argc, argv, &philo))
		ft_error(ARG_ERROR);
	philo.philosophe = malloc(sizeof(t_philo) * philo.argument.number_of_philo);
	if (!philo.philosophe)
		ft_error(ARG_ERROR);
	if (init_philo(&philo) != 1 )
		ft_error(ARG_ERROR);
	//printf("%lld\n", get_time() - philo.argument.start_time);
	if (thread_start(&philo) != 1)
	{
		free(philo.philosophe);
		ft_error(ARG_ERROR);
	}
	cleanup_table(&philo, &philo.argument);
	return (0);
}