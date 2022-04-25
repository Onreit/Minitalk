/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:03:07 by tjalo             #+#    #+#             */
/*   Updated: 2022/04/13 13:27:39 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>

# define BUFF_MAX 256

typedef struct s_minitalk
{
	char	g_buff[BUFF_MAX];
	int		g_i;
}				t_minitalk;

#endif