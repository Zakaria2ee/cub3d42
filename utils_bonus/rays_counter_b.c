/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_counter_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:44:12 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/14 15:58:07 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

double	get_ray_b(t_data *data, double angle, int i, int r);

void	rays_counter_b(t_data *data, double *rays)
{
	int		i;
	double	r;
	double	angle;

	i = -1;
	angle = data->player_a - 30;
	r = -30;
	while (++i < RSX)
	{
		if (angle >= 360)
			angle -= 360;
		else if (angle < 0)
			angle += 360;
		rays[i] = get_ray_b(data, angle, i, r);
		angle += 0.05;
		r += 0.05;
	}
}

static int	direction(int dirRay, int x, int y, t_data *data)
{
	if (dirRay == 'x' && (data->player_x > x))
		dirRay = 's';
	else if (dirRay == 'x')
		dirRay = 'n';
	else if (dirRay == 'y' && (data->player_y > y))
		dirRay = 'e';
	else
		dirRay = 'w';
	return (dirRay);
}

int	reach_wall(t_data *data, double angle, double *x, double *y)
{
	int	d_ray;

	*x = data->player_x;
	*y = data->player_y;
	while (!walls_checker3_b(*x, *y, 1 * sin(angle * PI / 180),
			1 * cos(angle * PI / 180), data))
	{
		*x += 1 * cos(angle * PI / 180);
		*y += 1 * sin(angle * PI / 180);
	}
	*x -= 1 * cos(angle * PI / 180);
	*y -= 1 * sin(angle * PI / 180);
	d_ray = walls_checker3_b(*x, *y, 0.1 * sin(angle * PI / 180),
			0.1 * cos(angle * PI / 180), data);
	while (!d_ray)
	{
		*x += 0.1 * cos(angle * PI / 180);
		*y += 0.1 * sin(angle * PI / 180);
		d_ray = walls_checker3_b(*x, *y, 0.1 * sin(angle * PI / 180),
				0.1 * cos(angle * PI / 180), data);
	}
	return (d_ray);
}

double	get_ray_b(t_data *data, double angle, int i, int r)
{
	double	x;
	double	y;
	double	ray;
	int		d_ray;

	d_ray = reach_wall(data, angle, &x, &y);
	ray = (sqrt(((data->player_x - x) * (data->player_x - x))
				+ ((data->player_y - y)
					* (data->player_y - y)))) * cos(r * PI / 180);
	if (ray < 1)
		ray = 1;
	data->dirRay[i][0] = direction(d_ray, x, y, data);
	data->dirRay[i][2] = data->is_door;
	data->is_door = 0;
	if (data->dirRay[i][0] == 's' || data->dirRay[i][0] == 'n')
		data->dirRay[i][1] = (int)(y * 4) % TEXY;
	else
		data->dirRay[i][1] = (int)(x * 4) % TEXX;
	return (ray);
}
