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
/*
void    action(t_philo *philo)
{
    pthread_mutex_lock(&philo->left_fork);
    pthread_mutex_lock(&philo->philo_arg->write_status);
	print_status(philo, FORK);
    pthread_mutex_unlock(&philo->philo_arg->write_status);
    if (!philo->right_fork) // philoが1人だった場合
    {
        pthread_mutex_unlock(&philo->left_fork);
        usleep(philo->philo_arg->to_die);
        return;
    }
    pthread_mutex_lock(philo->right_fork);
    pthread_mutex_lock(&philo->philo_arg->write_status);
    print_status(philo, FORK);
    pthread_mutex_unlock(&philo->philo_arg->write_status);
    pthread_mutex_lock(&philo->philo_arg->write_status);
    print_status(philo, EATING);
    pthread_mutex_unlock(&philo->philo_arg->write_status);
    pthread_mutex_lock(&philo->philo_arg->eating);
    philo->last_eat = get_time();
    pthread_mutex_unlock(&philo->philo_arg->eating);
    short_sleep(philo->philo_arg->to_eat);
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(&philo->left_fork);
    philo->times_eat++;
}
*/
void    think_and_sleep(t_philo *philo)
{
    print_status(philo, SLEEPING);
    short_sleep(philo->philo_arg->to_sleep);
    print_status(philo, THINKING);
} 
void    action_left(t_philo *philo)
{
    pthread_mutex_lock(&philo->left_fork);
	print_status(philo, FORK);
    if (!philo->right_fork) // philoが1人だった場合
    {
        pthread_mutex_unlock(&philo->left_fork);
        usleep(philo->philo_arg->to_die);
        return;
    }
    pthread_mutex_lock(philo->right_fork);
    print_status(philo, FORK);
    print_status(philo, EATING);
    pthread_mutex_lock(&philo->philo_arg->eating);
    philo->last_eat = get_time();
    //pthread_mutex_lock(&philo->philo_arg->meal_check);
    //pthread_mutex_unlock(&philo->philo_arg->meal_check);
    pthread_mutex_unlock(&philo->philo_arg->eating);
    short_sleep(philo->philo_arg->to_eat);
     philo->times_eat++;
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(&philo->left_fork);

}
void    go_to_action(t_philo *philo)
{
    if (philo->id_philo % 2 == 0)
    {
        pthread_mutex_lock(philo->right_fork);
	    print_status(philo, FORK);
        if (!philo->right_fork) // philoが1人だった場合
        {
            pthread_mutex_unlock(&philo->left_fork);
            usleep(philo->philo_arg->to_die);
            return;
        }
        pthread_mutex_lock(&philo->left_fork);
        print_status(philo, FORK);
        print_status(philo, EATING);
        pthread_mutex_lock(&philo->philo_arg->eating);
        philo->last_eat = get_time();
        //pthread_mutex_lock(&philo->philo_arg->meal_check);
        //pthread_mutex_unlock(&philo->philo_arg->meal_check);
        pthread_mutex_unlock(&philo->philo_arg->eating);
        short_sleep(philo->philo_arg->to_eat);
        philo->times_eat++;
        pthread_mutex_unlock(&philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        }
    else
        action_left(philo);
}