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
	//t_arg	*arg;
	int i;

	i = 0;
	if (!spread_argument(argc, argv, &philo))
	{
		printf("Argument is not corrct\n");
		exit(1);
	}	
	philo.philosophe = malloc(sizeof(t_philo) * philo.argument.number_of_philo);
	if (!philo.philosophe)
		exit(1);
	initialisation(&philo);
	printf("OK\n");
	while (i < philo.argument.number_of_philo)
	{
		pthread_mutex_destroy(&philo.philosophe[i].left_fork);
		i++;
	}
	return (0);
}

/*int main(int argc, char **argv)
{
    pthread_t               thread_id1;
    pthread_t               thread_id2;
    t_thread                     p;
    t_thread                     *pp;

    pp = (malloc(sizeof(t_thread) * 1));
    pp = &p;
    p.sum = 2;

    pthread_mutex_init(&p.mutex_write, NULL);			// obligatoire de init le mutex
    pthread_create(&thread_id1, NULL, thread, (void *)pp);
    pthread_create(&thread_id2, NULL, thread, (void *)pp);
	sleep(1);
	pthread_join(thread_id1, NULL);
	pthread_join(thread_id2, NULL);
	pthread_mutex_destroy(&p.mutex_write);
}*/
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
/*
//pthread_mutex_t  mutex;
int	main(int argc, char **argv)
{
	pthread_t	t[4];
	int i;
	t_thread th[4];
	t_thread p;

	
	int av;
	//th[0].sum = 0;

	i = 0;
	
	if (argc == 2)
	{
		av = ft_atoi(argv[1]);
		p.data = av / 4;
		
		while (i < 4)
		{
			th[i] = p;
			pthread_mutex_init(&th[i].arg.mutex_sum, NULL);
			i++;
		}
	
		i = 0;
		while (i < 4)
		{
			th[i].data = av / 4;
			i++;
		}
		i = 0;
		while (i < 4)
		{
			pthread_create(&t[i], NULL, thread, (void *)&th[i]);
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
		//printf("sum:%d\n", gl);
		return (0);
	}
}
*/

