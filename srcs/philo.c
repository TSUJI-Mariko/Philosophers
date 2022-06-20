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

int	main(int argc, char **argv)
{
	t_pa philo;
	
	if (!spread_argument(argc, argv, &philo))

		return (printf("%s\n", ARG_ERROR));
	philo.philosophe = malloc(sizeof(t_philo) * philo.argument.number_of_philo);
	if (!philo.philosophe)
		exit(1);
	init_philo(&philo);
	threading(philo);
	printf("%ld\n", get_time() - philo.argument.start_time);
	return (0);
}