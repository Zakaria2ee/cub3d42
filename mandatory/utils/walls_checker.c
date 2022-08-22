/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:06:20 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/22 14:12:53 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	walls_checker(int x, int y, t_data *data)
{
	if (data->map[(y + data->player_dy) / 50]
		[(x + data->player_dx) / 50] == '1')
		return (0);
	if (data->map[(y + data->player_dy) / 50][x / 50] == '1'
		&& data->map[y / 50][(x + data->player_dx) / 50] == '1')
		return (0);
	return (1);
}

int	walls_checker2(int x, int y, t_data *data)
{
	float	dx;
	float	dy;

	dx = PX * cos(data->player_a * PI / 180);
	dy = PX * sin(data->player_a * PI / 180);
	if (data->map[(int)(y - dy) / 50][(int)(x - dx) / 50] == '1')
		return (0);
	if (data->map[(int)(y - dy) / 50][(int)(x / 50)] == '1'
	&& data->map[(int)(y / 50)][(int)(x - dx) / 50] == '1')
		return (0);
	return (1);
}

int	walls_checker3(double x, double y, int px, t_data *data)
{
	int	dy;
	int	dx;

	dy = px * cos(data->player_a);
	dx = px * sin(data->player_a);
	if (data->map[(int)(y + dy) / 50][(int)(x / 50)] == '1')
		return ('y');
	if (data->map[(int)(y / 50)][(int)(x + dx) / 50] == '1')
		return ('x');
	if (data->map[(int)(y + dy) / 50][(int)(x + dx) / 50] == '1')
		return (1);
	return (0);
}

int	walls_checker31(double x, double y, double angle, t_data *data)
{
	int	dy;
	int	dx;

	dy = 1 * cos(angle * PI / 180);
	dx = 1 * sin(angle * PI / 180);
	if (data->map[(int)(y + dy) / 50][(int)(x / 50)] == '1')
		return ('y');
	if (data->map[(int)(y / 50)][(int)(x + dx) / 50] == '1')
		return ('x');
	if (data->map[(int)(y + dy) / 50][(int)(x + dx) / 50] == '1')
		return (1);
	return (0);
}

int	walls_checker301(double x, double y, double angle, t_data *data)
{
	int	dy;
	int	dx;

	dy = 0.1 * cos(angle * PI / 180);
	dx = 0.1 * sin(angle * PI / 180);
	if (data->map[(int)(y + dy) / 50][(int)(x / 50)] == '1')
		return ('y');
	if (data->map[(int)(y / 50)][(int)(x + dx) / 50] == '1')
		return ('x');
	if (data->map[(int)(y + dy) / 50][(int)(x + dx) / 50] == '1')
		return (1);
	return (0);
}
