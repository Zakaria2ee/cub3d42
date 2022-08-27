/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_3D_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:23:52 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/27 14:15:44 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rendering_3d_map(t_data *data)
{
	double	rays[RSX];

	rays_counter(data, rays);
	put_black_background(data);
	rays_to_image(data, rays);
}

int	walls_checker310(double x, double y, double angle, t_data *data)
{
	float	dy;
	float	dx;

	dx = 20 * cos(angle * PI / 180);
	dy = 20 * sin(angle * PI / 180);
	if (data->map[(int)(y + dy) / 50][(int)(x / 50)] == '1')
		return ('y');
	if (data->map[(int)(y / 50)][(int)(x + dx) / 50] == '1')
		return ('x');
	if (data->map[(int)(y + dy) / 50][(int)(x + dx) / 50] == '1')
		return (1);
	return (0);
}

int	ini(int *i, double *rays, int current_x)
{
	*i = (RSX / 2 / tan(30 * PI / 180) * 50 / rays[current_x]);
	if (*i > RSY)
		*i -= (*i - RSY) / 2;
	return ((RSX / 2 / tan(30 * PI / 180) * 50 / rays[current_x]));
}
