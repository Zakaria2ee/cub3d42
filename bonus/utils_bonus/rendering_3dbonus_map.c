/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_3dbonus_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:55:25 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/22 16:56:58 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	rendering_3dbonus_map(t_data *data)
{
	double	rays[RSX];

	rays_counter_b(data, rays);
	put_black_background(data);
	rays_to_image_b(data, rays);
}

int	walls_checker301_b(double x, double y, double angle, t_data *data)
{
	float	dx;
	float	dy;

	dx = 0.1 * cos(angle * PI / 180);
	dy = 0.1 * sin(angle * PI / 180);
	if (data->map[(int)(y + dy) / 50][(int)(x / 50)] == 'D'
		|| data->map[(int)(y / 50)][(int)(x + dx) / 50] == 'D')
		data->is_door = 'D';
	if (data->map[(int)(y + dy) / 50][(int)(x / 50)] == '1'
		|| data->map[(int)(y + dy) / 50][(int)(x / 50)] == 'D')
		return ('y');
	if (data->map[(int)(y / 50)][(int)(x + dx) / 50] == '1'
		|| data->map[(int)(y / 50)][(int)(x + dx) / 50] == 'D')
		return ('x');
	if (data->map[(int)(y + dy) / 50][(int)(x + dx) / 50] == '1'
		|| data->map[(int)(y + dy) / 50][(int)(x / 50)] == 'D')
		return (1);
	return (0);
}
