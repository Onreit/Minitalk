/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:52:18 by tjalo             #+#    #+#             */
/*   Updated: 2022/04/13 13:12:20 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (0);
}

int	ft_atoi(const char *s)
{
	unsigned long long	nb;
	int					i;

	nb = 0;
	i = 0;
	while ((s[i] > 8 && s[i] < 14) || s[i] == 32)
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		nb = (nb * 10) + (s[i++] - '0');
	return (nb);
}

int	parse_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	send_signal(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c & (1 << i)))
		{
			if (kill(pid, SIGUSR1) == -1)
				return (ft_error("Error PID.\n"));
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (ft_error("Error PID.\n"));
		}
		i--;
		usleep(250);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	if (ac != 3)
		return (ft_error("You need three arguments.\n"));
	if (parse_pid(av[1]) == 0)
		return (ft_error("Error PID.\n"));
	i = 0;
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		if (!send_signal(pid, av[2][i]))
			return (0);
		i++;
	}
	if (!send_signal(pid, '\0'))
		return (0);
	return (0);
}
