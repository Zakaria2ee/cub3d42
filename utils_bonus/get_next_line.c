/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:08:53 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/14 14:47:11 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

char	*get_next_line(int fd)
{
	char	*s;
	char	*tmp;

	s = malloc(1000);
	tmp = s;
	while (read(fd, tmp, 1) > 0 && *tmp++ != '\n')
	{
	}
	if (tmp > s)
	{
		*tmp = 0;
		return (s);
	}
	else
	{
		free(s);
		return (NULL);
	}
}
