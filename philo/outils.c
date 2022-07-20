/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:35:54 by mtsuji            #+#    #+#             */
/*   Updated: 2022/07/20 12:11:36 by msuji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	print_status(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->philo_arg->is_dead);
	if (philo->philo_arg->stop == 1)
	{
		pthread_mutex_unlock(&philo->philo_arg->is_dead);
		return ;
	}
	if (current_time(philo) >= 0 && philo->philo_arg->stop == 0)
	{
		pthread_mutex_lock(&philo->philo_arg->write_status);
		//printf("%lld\t", current_time(philo));
		ft_putnbr_fd(current_time(philo), 1);
		//printf("Philo %d %s \n", philo->id_philo, str);
		write(1, "\tPhilo ", 7);
		ft_putnbr_fd(philo->id_philo, 1);
		write(1, " ", 1);
		write(1, str, ft_strlen(str));
		write(1, "\n", 2);
		pthread_mutex_unlock(&philo->philo_arg->write_status);
	}
	pthread_mutex_unlock(&philo->philo_arg->is_dead);
}

void	ft_putnbr_fd(int nb, int fd)
{
	char	c;
	long	a;

	a = nb;
	if (a < 0)
	{
		write(fd, "-", 1);
		a = a * -1;
	}
	if (a >= 10)
	{
		ft_putnbr_fd((int)(a / 10), fd);
		ft_putnbr_fd((int)(a % 10), fd);
	}
	else
	{
		c = a + '0';
		write(fd, &c, 1);
	}
}

void	ft_usleep(t_philo *philo)
{
	if (usleep(1000) == -1)
		ft_error(SLEEP_ERROR, philo);
}
