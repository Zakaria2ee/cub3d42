/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:06:20 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/22 16:57:01 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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

int	walls_checker2_b(int x, int y, t_data *data)
{
	float	dy;
	float	dx;

	dx = PX * cos(data->player_a * PI / 180);
	dy = PX * sin(data->player_a * PI / 180);
	if (data->map[(int)(y - dy) / 50][(int)(x - dx) / 50] == '1'
			|| data->map[(int)(y - dy) / 50][(int)(x - dx) / 50] == 'D')
		return (0);
	if (data->map[(int)(y - dy) / 50][(int)(x / 50)] == '1'
	|| data->map[(int)(y - dy) / 50][(int)(x / 50)] == 'D')
		return (0);
	return (1);
}

int	walls_checker3_b(double x, double y, double angle, t_data *data)
{
	float	dx;
	float	dy;

	dx = 15 * cos(angle * PI / 180);
	dy = 15 * sin(angle * PI / 180);
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

int	walls_checker320_b(double x, double y, t_data *data)
{
	float	dx;
	float	dy;

	dx = 20 * cos(data->player_a * PI / 180);
	dy = 20 * sin(data->player_a * PI / 180);
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

int	walls_checker31_b(double x, double y, double angle, t_data *data)
{
	float	dx;
	float	dy;

	dx = 1 * cos(angle * PI / 180);
	dy = 1 * sin(angle * PI / 180);
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
