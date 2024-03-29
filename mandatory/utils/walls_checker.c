/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:06:20 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/25 09:38:19 by zboudair         ###   ########.fr       */
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

	dx = 20 * cos(data->player_a * PI / 180);
	dy = 20 * sin(data->player_a * PI / 180);
	if (data->map[(int)(y - dy) / 50][(int)(x - dx) / 50] == '1')
		return (0);
	if (data->map[(int)(y - dy) / 50][(int)(x / 50)] == '1'
	&& data->map[(int)(y / 50)][(int)(x - dx) / 50] == '1')
		return (0);
	return (1);
}

int	walls_checker3(double x, double y, int px, t_data *data)
{
	float	dy;
	float	dx;

	dx = px * cos(data->player_a * PI / 180);
	dy = px * sin(data->player_a * PI / 180);
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
	float	dy;
	float	dx;

	dx = 1 * cos(angle * PI / 180);
	dy = 1 * sin(angle * PI / 180);
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
	float	dy;
	float	dx;

	dx = 0.1 * cos(angle * PI / 180);
	dy = 0.1 * sin(angle * PI / 180);
	if (data->map[(int)(y + dy) / 50][(int)(x / 50)] == '1')
		return ('y');
	if (data->map[(int)(y / 50)][(int)(x + dx) / 50] == '1')
		return ('x');
	if (data->map[(int)(y + dy) / 50][(int)(x + dx) / 50] == '1')
		return (1);
	return (0);
}
