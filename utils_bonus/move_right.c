/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:58:15 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/14 14:59:50 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	move_right(t_data *data)
{
	int	angle;
	int	x;
	int	y;

	x = data->player_x;
	y = data->player_y;
	angle = data->player_a;
	angle += 90;
	if (angle > 360)
		angle -= 360;
	else if (angle < 0)
		angle += 360;
	if (walls_checker3_b(data->player_x, data->player_y,
			PX * sin(angle * PI / 180), PX * cos(angle * PI / 180), data))
		return ;
	data->player_x += PX * cos(angle * PI/180);
	data->player_y += PX * sin(angle * PI/180);
	rendering_3dbonus_map(data);
	mini_map(data);
}
