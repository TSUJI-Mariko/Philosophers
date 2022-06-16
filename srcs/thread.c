/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:12:37 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/14 14:54:39 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

extern int gl;
//extern pthread_mutex_t mutex;
void	*thread(void *arg)
{
	t_thread *th;
	int j;
	//pthread_mutex_t mutex;

	th = (t_thread *)arg;
	j = 0;	
	while (j < th->data)
	{
		pthread_mutex_lock(&th->arg.mutex_sum);
		gl = gl + 1;
		pthread_mutex_unlock(&th->arg.mutex_sum);
		j++;
	}

	return NULL;
}
