/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:03:19 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/12 17:21:26 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_back(t_data *data)
{
	if (!walls_checker2(data->player_x, data->player_y,
			PX * sin(data->player_a * PI / 180),
			PX * cos(data->player_a * PI / 180), data))
		return ;
	data->player_x -= round(PX * cos(data->player_a * PI / 180));
	data->player_y -= round(PX * sin(data->player_a * PI / 180));
	rendering_3d_map(data);
}