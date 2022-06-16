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

int gl = 0;
//pthread_mutex_t  mutex;
int	main(int argc, char **argv)
{
	pthread_t	t[4];
	int i;
	t_thread th[4];
	int av;
	//th[0].sum = 0;

	i = 0;
	while (i < 4)
	{
		pthread_mutex_init(&th[i].arg.mutex_sum, NULL);
		i++;
	}
	if (argc == 2)
	{
		av = ft_atoi(argv[1]);
		i = 0;
		while (i < 4)
		{
			th[i].data = av / 4;
			i++;
		}
		i = 0;
		while (i < 4)
		{
			pthread_create(&t[i], NULL, thread, &th[i]);
			i++;
		}
		i = 0;
		while (i < 4)
		{
			pthread_join(t[i], NULL);
			i++;
		}
		i = 0;
		while (i < 4)
		{
			pthread_mutex_destroy(&th[i].arg.mutex_sum);
			i++;
		}
		printf("sum:%d\n", gl);
		return (0);
	}
}

