/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:50:50 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/19 16:01:31 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_map(char **argv, t_data *data)
{
	char	*s;

	(void)argv;
	s = get_next_line(data->fd);
	data->saved = NULL;
	while (s)
	{
		data->saved = ft_strjoin(data->saved, s);
		free(s);
		s = get_next_line(data->fd);
	}
	close(data->fd);
}