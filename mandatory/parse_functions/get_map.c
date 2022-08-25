/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:50:50 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/25 08:41:18 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_map(t_data *data)
{
	char	*s;

	s = get_next_line(data->fd);
	data->saved = NULL;
	while (s)
	{
		data->saved = ft_strjoin(data->saved, s);
		free(s);
		s = get_next_line(data->fd);
	}
	if (!data->saved)
		ft_exit("Error\nYou Need a Map\n");
	close(data->fd);
}
