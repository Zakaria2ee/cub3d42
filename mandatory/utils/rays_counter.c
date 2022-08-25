/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:44:12 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/25 16:12:40 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static double	get_ray(t_data *data, double angle, int i, int r);

void	rays_counter(t_data *data, double *rays)
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
		rays[i] = get_ray(data, angle, i, r);
		angle += 0.05;
		r += 0.05;
	}
}

static int	direction(int dirray, int x, int y, t_data *data)
{
	if (dirray == 'x' && (data->player_x > x))
		dirray = 's';
	else if (dirray == 'x')
		dirray = 'n';
	else if (dirray == 'y' && (data->player_y > y))
		dirray = 'e';
	else
		dirray = 'w';
	return (dirray);
}

int	reach_wall(t_data *data, double angle, double *x, double *y)
{
	int	d_ray;

	*x = data->player_x;
	*y = data->player_y;
	while (!walls_checker31(*x, *y, angle, data))
	{
		*x += 1 * cos(angle * PI / 180);
		*y += 1 * sin(angle * PI / 180);
	}
	*x -= 1 * cos(angle * PI / 180);
	*y -= 1 * sin(angle * PI / 180);
	d_ray = walls_checker301(*x, *y, angle, data);
	while (!d_ray)
	{
		*x += 0.1 * cos(angle * PI / 180);
		*y += 0.1 * sin(angle * PI / 180);
		d_ray = walls_checker301(*x, *y, angle, data);
	}
	return (d_ray);
}

static int	get_t_width_dir(t_data *data, double x, double y, int d_ray)
{
	if (d_ray == 's')
		return ((int)round(y * ((double)data->s.w / 50.0)) % data->s.w);
	else if (d_ray == 'n')
		return ((int)round(y * ((double)data->n.w / 50.0)) % data->n.w);
	else if (d_ray == 'e')
		return ((int)round(x * ((double)data->e.w / 50.0)) % data->e.h);
	else
		return ((int)round(x * ((double)data->we.w / 50.0)) % data->we.h);
}

static double	get_ray(t_data *data, double angle, int i, int r)
{
	double	x;
	double	y;
	double	ray;
	int		d_ray;

	d_ray = reach_wall(data, angle, &x, &y);
	ray = (sqrt(((data->player_x - x) * (data->player_x - x))
				+ ((data->player_y - y) * (data->player_y - y))))
		* cos(r * PI / 180);
	if (ray < 1)
		ray = 1;
	data->dirray[i][0] = direction(d_ray, x, y, data);
	data->dirray[i][1] = get_t_width_dir(data, x, y, data->dirray[i][0]);
	return (ray);
}
