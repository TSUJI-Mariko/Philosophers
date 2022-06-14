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
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>


typedef struct s_thread
{
	int	data;
	int sum;
	pthread_mutex_t	mutex;
}	t_thread;

typedef struct s_sum
{
	int sum;
}	t_sum;

//thread.c
void	*thread(void *arg);
//outils.c
int	ft_atoi(const char *str);
#endif
