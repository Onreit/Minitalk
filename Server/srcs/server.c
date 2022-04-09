/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:27:20 by tjalo             #+#    #+#             */
/*   Updated: 2022/04/08 16:57:18 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

t_minitalk	g_talk;

void	handler(int sign, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sign == SIGUSR1)
		ft_buf('1', &g_talk);
	else if (sign == SIGUSR2)
		ft_buf('0', &g_talk);
}

void	ft_put_bin_to_char(char *str)
{
	int		bin;
	int		res;
	int		decimal;
	int		base;
	char	c;

	bin = ft_atoi(str);
	res = 0;
	decimal = 0;
	base = 1;
	c = 0;
	while (bin > 0)
	{
		res = bin % 10;
		decimal = decimal + res * base;
		bin = bin / 10;
		base = base * 2;
	}
	c = (char)decimal;
	ft_put_buff(&g_talk, c);
}

void	ft_buf(char c, t_minitalk *talk)
{
	talk->g_buff[talk->g_i] = c;
	talk->g_i++;
	if (talk->g_i == BUFF_MAX)
	{
		ft_put_bin_to_char(talk->g_buff);
		talk->g_i = 0;
	}
}

void	ft_putnbr(long nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		nb = nb + (int) '0';
		write(1, &nb, 1);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	info;

	(void)av;
	if (ac != 1)
	{
		return (0);
	}
	ft_putnbr(getpid());
	write(1, "\n", 1);
	ft_memset(&g_talk, 0, sizeof(g_talk));
	ft_memset(&info, 0, sizeof(info));
	info.sa_sigaction = &handler;
	info.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&info.sa_mask);
	sigaction(SIGUSR1, &info, NULL);
	sigaction(SIGUSR2, &info, NULL);
	while (1)
		;
	return (0);
}
