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
	pthread_mutex_t mutex_write;
	int	to_die;
	int to_eat;
	int to_sleep;
	int number_of_philo;
	
	int must_eat;
}		t_arg;

typedef struct s_philo
{
	int	times_eat;
	int	finish_eat;
	int id_philo;
	pthread_mutex_t	left_fork;
	pthread_mutex_t *right_fork;
	t_arg philo_arg;
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


//argv_check
int    check_arg(int argc, char **argv);
int    spread_argument(int argc, char **argv, t_pa *philo);
//thread.c
void	*thread(void *arg);
int	initialisation(t_pa *p);
//outils.c
int	ft_atoi(const char *str);
int	ft_strlen(char *s);

#endif
