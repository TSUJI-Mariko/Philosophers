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

#include "../includes/philo.h"

int    check_arg(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] > '0' || argv[i][j] < '9' 
                || ft_strlen(argv[i]) > 10)
                return(0);
            j++;
        }   
        i++;
    }
    return (1);
}

int    spread_argument(int argc, char **argv, t_pa *p)
{
    if (check_arg(argc, argv) || argc == 5 || argc == 6)
    {
        p->argument.number_of_philo = ft_atoi(argv[1]);
        p->argument.to_die = ft_atoi(argv[2]);
        p->argument.to_eat = ft_atoi(argv[3]);
        p->argument.to_sleep = ft_atoi(argv[4]);
        p->argument.must_eat = 0;
        if (argc == 6)
            p->argument.must_eat = ft_atoi(argv[5]);
        if ( p->argument.number_of_philo <= 0 || p->argument.to_die <= 0 
         || p->argument.to_eat <= 0 || p->argument.to_sleep <= 0 ) 
         return (0);
        return (1);
    }
    return (0);
}

int	initialisation(t_pa *p)
{
	int i;

	i = 0;
	while (i < p->argument.number_of_philo)
	{
		p->philosophe[i].id_philo = i + 1;
		p->philosophe[i].times_eat = 0;
		p->philosophe[i].finish_eat = 0;
		pthread_mutex_init(&p->philosophe[i].left_fork, NULL);
		if (p->argument.number_of_philo == 1)
			return (0);
		if (i + 1 == p->argument.number_of_philo)
			p->philosophe[i].right_fork = &p->philosophe[0].left_fork; 
		else
			p->philosophe[i].right_fork = &p->philosophe[i + 1].left_fork;
        printf("id%d:%d\n", i, p->philosophe[i].id_philo);
		i++;
	}
	return (0);
}