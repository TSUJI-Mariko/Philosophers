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

void	*thread(void *arg)
{
	t_thread *i;
	int j;
	t_sum sum;

	i = (t_thread *)arg;
	j = 0;
	//i->sum = 0;	
	while (j < i->data)
	{
		pthread_mutex_lock(&i->mutex);
		sum.sum = sum.sum + 1;
		pthread_mutex_unlock(&i->mutex);
		j++;
	}
	return NULL;
}
