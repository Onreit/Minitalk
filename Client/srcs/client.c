/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:52:18 by tjalo             #+#    #+#             */
/*   Updated: 2022/04/09 12:41:48 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

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

	i = 6;
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
		usleep(800);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	if (ac != 3)
		return (0);
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
