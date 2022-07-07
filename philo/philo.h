/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:16:39 by mtsuji            #+#    #+#             */
/*   Updated: 2022/07/07 16:36:00 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "argument.h"
# include "struct.h"

//argv_check
int			check_arg(char **argv);
int			spread_argument(int argc, char **argv, t_pa *philo);
void		init_mutex(t_pa *philo);

//thread.c
void		*dead(void *arg);
void		routine(t_philo *philo);
void		*thread(void *arg);
int			init_philo(t_pa *p);
int			thread_start(t_pa *philo);

//outils.c
int			ft_atoi(const char *str);
int			ft_strlen(char *s);

//outil2.c
int			stopper(int stop, t_philo *philo);
void		print_status(t_philo *philo, char *str);
int			ft_error(char *str);
long long	get_time(void);
void		short_sleep(long int time);
void		death_check(t_philo *philo, int dead);
long long	current_time(t_philo *philo);

//action
void		action(t_philo *philo);
void		think_and_sleep(t_philo *philo);
void		go_to_action(t_philo *philo);
void		action_left(t_philo *philo);
void		action_right(t_philo *philo);

//main
void		cleanup_table(t_pa *philo, t_arg *arg);
#endif
