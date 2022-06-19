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
# include "argument.h"
# include "struct.h"


//argv_check
int    check_arg(int argc, char **argv);
int    spread_argument(int argc, char **argv, t_pa *philo);
void	init_mutex(t_pa *philo);
//thread.c
void	*thread(void *arg);
int	init_philo(t_pa *p);
void	threading(t_pa philo);
//outils.c
int	ft_atoi(const char *str);
int	ft_strlen(char *s);
//outil2.c
void    print_status(t_philo *philo, char *str);
long int    get_time(void);
void    short_sleep(long int time);
//action
void	action(t_philo *philo);

#endif
