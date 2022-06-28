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

#include "../includes/philo.h"

void cleanup_table(t_pa philo)
{
	int i;
	i = -1;

	while (++i < philo.argument.number_of_philo)
	{
		pthread_mutex_destroy(&philo.philosophe[i].left_fork);
		pthread_mutex_destroy(&philo.philosophe[i].philo_arg->write_status);
		//free(&philo.philosophe[i]);
	}
	printf("%lld\tevery philosophers eated %d times\n", get_time() - philo.argument.start_time, philo.argument.must_eat);
}


int	main(int argc, char **argv)
{
	t_pa philo;
	
	if (!spread_argument(argc, argv, &philo))

		return (printf("%s\n", ARG_ERROR));
	philo.philosophe = malloc(sizeof(t_philo) * philo.argument.number_of_philo);
	if (!philo.philosophe)
		exit(1);
	if (init_philo(&philo) != 1 || thread_start(&philo) != 1)
	{
		free(philo.philosophe);
		return (0);
	}
	//printf("%ld\n", get_time() - philo.argument.start_time);

	cleanup_table(philo);
	return (0);
}