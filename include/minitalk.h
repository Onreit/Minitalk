/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:03:07 by tjalo             #+#    #+#             */
/*   Updated: 2022/04/09 12:49:11 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>

# define BUFF_MAX 7
# define BUF_MAX 256

typedef struct s_minitalk
{
	char	g_buff[BUFF_MAX];
	char	g_buf[BUF_MAX];
	int		g_i;
	int		g_e;
}				t_minitalk;

int		ft_atoi(const char *str);
void	ft_buf(char c, t_minitalk *talk);
int		ft_error(char *str);
void	ft_put_bin_to_char(char *str);
void	ft_display(t_minitalk *talk);
void	ft_put_buff(t_minitalk *talk, char c);
void	*ft_memset(void *b, int c, size_t len);

#endif