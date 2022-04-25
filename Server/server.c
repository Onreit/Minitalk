/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:27:20 by tjalo             #+#    #+#             */
/*   Updated: 2022/04/19 19:07:56 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_minitalk	g_talk;

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*p;

	p = b;
	i = 0;
	while (i < len)
		p[i++] = c;
	return (b);
}

void	ft_buf(unsigned char c, t_minitalk *talk)
{
	if (c != '\0')
	{
		talk->g_buff[talk->g_i] = c;
		talk->g_i++;
	}
	else if (c == '\0')
	{
		write(1, talk->g_buff, talk->g_i);
		write(1, "\n", 1);
		talk->g_i = 0;
	}
	if (talk->g_i == BUFF_MAX)
	{
		write(1, talk->g_buff, talk->g_i);
		talk->g_i = 0;
	}
}

void	handler(int sign)
{
	static unsigned char	c = 0;
	static int				bits = 0;

	if (sign == SIGUSR1)
		c |= 0x80 >> bits;
	bits++;
	if (bits == 8)
	{
		ft_buf(c, &g_talk);
		c = 0;
		bits = 0;
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
		write(1, "Only one argument is needed.\n", 30);
		return (0);
	}
	ft_putnbr(getpid());
	write(1, "\n", 1);
	ft_memset(&g_talk, 0, sizeof(g_talk));
	ft_memset(&info, 0, sizeof(info));
	info.sa_handler = &handler;
	info.sa_flags = SA_RESTART;
	sigemptyset(&info.sa_mask);
	sigaction(SIGUSR1, &info, NULL);
	sigaction(SIGUSR2, &info, NULL);
	while (1)
		;
	return (0);
}
