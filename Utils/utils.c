/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:39:06 by tjalo             #+#    #+#             */
/*   Updated: 2022/04/08 15:32:56 by tjalo            ###   ########.fr       */
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

void	ft_put_buff(t_minitalk *talk, char c)
{
	if (c == '\0')
	{
		write(1, "\n", 1);
		ft_display(talk);
		talk->g_e = 0;
	}
	if (c != '\0')
	{
		talk->g_buf[talk->g_e] = c;
		talk->g_e++;
	}
	if (talk->g_e == BUF_MAX)
	{
		ft_display(talk);
		talk->g_e = 0;
	}
}

void	ft_display(t_minitalk *talk)
{
	write(1, talk->g_buf, talk->g_e);
	talk->g_e = 0;
}
