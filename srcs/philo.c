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

/*
int	main(int argc, char **argv)
{
	if (argc == 4)
	{

	}
	else if (argc == 5)
	{
		
	}
	return (0);
}*/

int	main(int argc, char **argv)
{
	pthread_t	t[100];
	int i;
	t_thread th[100];
	t_sum sum;
	int av;

	i = 0;
	sum.sum = 0;
	pthread_mutex_init(&th->mutex, NULL);
	if (argc == 2)
	{
		av = ft_atoi(argv[1]);
		i = 0;
		while (i < 10)
		{
			th[i].data = av / 10;
			i++;
		}
		i = 0;
		while (i < 10)
		{
			pthread_create(&t[i], NULL, thread, &th[i]);
			i++;
		}
		i = 0;
		while (i < 10)
		{
			pthread_join(t[i], NULL);
			i++;
		}
		pthread_mutex_destroy(&th->mutex);
			printf("sum:%d\n", sum.sum);
		return (0);
	}
}
