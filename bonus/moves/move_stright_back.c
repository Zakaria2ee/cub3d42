/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stright_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:01:42 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/22 16:55:28 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	if_cond(t_data *data);

void	move_stright_b(t_data *data)
{
	if (walls_checker320_b(data->player_x, data->player_y, data))
	{
		if_cond(data);
	}
	else if (!walls_checker320_b(data->player_x, data->player_y, data))
	{
		data->player_x += round(PX * cos(data->player_a * PI / 180));
		data->player_y += round(PX * sin(data->player_a * PI / 180));
	}
	rendering_3dbonus_map(data);
	mini_map(data);
}

void	move_back_b(t_data *data)
{
	if (!walls_checker2_b(data->player_x, data->player_y, data))
		return ;
	data->player_x -= round(PX * cos(data->player_a * PI / 180));
	data->player_y -= round(PX * sin(data->player_a * PI / 180));
	rendering_3dbonus_map(data);
	mini_map(data);
}

void	if_cond(t_data *data)
{
	if (data->map[data->player_y / 50][(data->player_x
			+ (int)round(PX * cos(data->player_a * PI / 180))) / 50] != '1'
		&& data->map[data->player_y / 50][(data->player_x +
			(int)round(PX * cos(data->player_a * PI / 180))) / 50] != 'D')
	{
		if (data->player_a != 270 && data->player_a != 90)
			data->player_x += round(PX * cos(data->player_a * PI / 180));
	}
	if (data->map[(data->player_y +(int)round(
					PX * sin(data->player_a * PI / 180))) / 50]
		[data->player_x / 50] != '1'
		&& data->map[(data->player_y
				+(int)round(PX * sin(data->player_a * PI / 180))) / 50]
		[data->player_x / 50] != 'D')
	{
		if (data->player_a != 0 && data->player_a != 180)
			data->player_y += round(PX * sin(data->player_a * PI / 180));
	}
	else
	{
		rendering_3dbonus_map(data);
		mini_map(data);
		return ;
	}
}
