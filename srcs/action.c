/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:38:45 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/19 18:38:47 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    action(t_philo *philo)
{
    //int j;

    //j = 0;
    //char *str = "bonjour coucou!";
    pthread_mutex_lock(&philo->left_fork);
    pthread_mutex_lock(&philo->philo_arg->write_status);
	/*while (str[j])
	{
		printf("%c", str[j]);
		j++;
	}*/
	print_status(philo, EATING);
    pthread_mutex_unlock(&philo->philo_arg->write_status);
    pthread_mutex_unlock(&philo->left_fork);
    pthread_mutex_lock(&philo->philo_arg->write_status);
    print_status(philo, SLEEPING);
    pthread_mutex_unlock(&philo->philo_arg->write_status);

}