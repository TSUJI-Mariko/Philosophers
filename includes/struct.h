/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:52:29 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/19 12:52:36 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_arg
{
	pthread_mutex_t is_dead;
	pthread_mutex_t write_status;
    pthread_mutex_t eating;
    pthread_mutex_t meal_check;
    pthread_mutex_t thinking;
	pthread_mutex_t finish;
	int	to_die;
	int stop;
	long long to_eat;
	int to_sleep;
	int number_of_philo;
	long long start_time;
	int finish_eat;
	int must_eat;
}		t_arg;

typedef struct s_philo
{
	int	times_eat;
	//int	last_eat;
	int id_philo;
	int	stop;
    long long last_eat;
    pthread_t thread;
	pthread_t dead;
	pthread_mutex_t	left_fork;
	pthread_mutex_t *right_fork;
	t_arg *philo_arg;
}		t_philo;

typedef struct s_pa
{
	t_philo		*philosophe;
	t_arg		argument;
	int i;
}				t_pa;
#endif
