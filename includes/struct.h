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
	int	to_die;
	long long to_eat;
	int to_sleep;
	int number_of_philo;
	long int start_time;
	int must_eat;
}		t_arg;

typedef struct s_philo
{
	int	times_eat;
	int	last_eat;
	int id_philo;
    pthread_t thread;
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

/*typedef struct s_thread
{
	int	data;
	int sum;
	//pthread_mutex_t	mutex;
	t_arg arg;

}		t_thread;*/

#endif
