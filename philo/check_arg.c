/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:13:58 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/18 12:14:01 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    check_arg(char **argv)
{
    int i;
    int j;

    i = 1;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] >= '0' && argv[i][j] <= '9')
                j++; 
            else
                return(1);
        }   
        //if (ft_strlen(argv[i]) < 11)
        //    return (1);
        i++;
    }
    return (0);
}

int    spread_argument(int argc, char **argv, t_pa *p)
{
    if ((argc == 5 || argc == 6) && !check_arg(argv))
    {
        p->argument.number_of_philo = ft_atoi(argv[1]);
        p->argument.to_die = ft_atoi(argv[2]);
        p->argument.to_eat = ft_atoi(argv[3]);
        p->argument.to_sleep = ft_atoi(argv[4]);
        p->argument.must_eat = 0;
        p->argument.finish_eat = 0;
        p->argument.stop = 0;
        p->argument.start_time = 0;
        if (argc == 6)
            p->argument.must_eat = ft_atoi(argv[5]);
        else
            p->argument.must_eat = -1;
        if ( p->argument.number_of_philo <= 0 || p->argument.to_die <= 0 
         || p->argument.to_eat <= 0 || p->argument.to_sleep <= 0) 
         return (0);
        return (1);
    }
    //init_mutex(p);
    return (0);
}

void    init_mutex(t_pa *philo)
{
    pthread_mutex_init(&philo->argument.write_status, NULL);
    //pthread_mutex_init(&philo->argument.meal_check, NULL);
    pthread_mutex_init(&philo->argument.finish, NULL);
    pthread_mutex_init(&philo->argument.eating, NULL);
    pthread_mutex_init(&philo->argument.is_dead, NULL);
}

int	init_philo(t_pa *p)
{
	int i;

    p->argument.start_time = get_time();
    init_mutex(p);
	i = 0;
	while (i < p->argument.number_of_philo)
	{
		p->philosophe[i].id_philo = i + 1;
		p->philosophe[i].times_eat = 0;
        p->philosophe[i].stop = 0;
        p->philosophe[i].stop_eat = 0;
		p->philosophe[i].last_eat = p->argument.start_time;
        p->philosophe[i].right_fork = NULL;
		pthread_mutex_init(&p->philosophe[i].left_fork, NULL);
		if (p->argument.number_of_philo == 1)
			return (1);
		if (i + 1 == p->argument.number_of_philo)
			p->philosophe[i].right_fork = &p->philosophe[0].left_fork; 
		else
			p->philosophe[i].right_fork = &p->philosophe[i + 1].left_fork;
		i++;
	}
	return (1);
}