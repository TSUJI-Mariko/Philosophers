/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:16:39 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/14 13:36:10 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define SUM 0
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>


typedef struct s_arg
{
	pthread_mutex_t mutex_sum;
}	t_arg;

typedef struct s_thread
{
	int	data;
	int sum;
	//pthread_mutex_t	mutex;
	t_arg arg;
}	t_thread;

typedef struct s_philo
{
	int	to_die;
	int to_eat;
	int to_sleep;
	int number_of_philo;
	int id_philo;
	pthread_mutex_t	left_fork;
	pthread_mutex_t right_fork;
	t_arg a;
}	t_philo;

//thread.c
void	*thread(void *arg);
//outils.c
int	ft_atoi(const char *str);
#endif
