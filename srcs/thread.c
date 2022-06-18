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


//extern pthread_mutex_t mutex;
/*void	*thread(void *arg)
{
	t_thread *th;
	int j;
	//pthread_mutex_t mutex;
	char *str = "bonjour coucou!";
	th = (t_thread *)arg;	
	j = 0;	
	pthread_mutex_lock(&th->mutex);
	while (str[j])
	{
		printf("%c", str[j]);
		j++;
	}
	printf("\n");
	pthread_mutex_unlock(&th->mutex);
	return NULL;
}*/
/*
void    *thread(void *pp)
{
    char *str;
    int i = 0;
    t_thread *ppp;

    ppp = (t_thread *)pp;
    str = "thread 1 : coucou ca va ? \n";
    pthread_mutex_lock(&ppp->mutex_write); // si on enleve ici
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    pthread_mutex_unlock(&ppp->mutex_write); // si on enleve ici
    return (NULL);
}*/

