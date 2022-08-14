/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:06:20 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/14 16:13:10 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int	walls_checker2(int x, int y, float dy, float dx, t_data *data)
{
	if (data->map[(int)(y - dy)/50][(int)(x - dx)/50] == '1')
		return (0);
	if (data->map[(int)(y - dy) / 50][(int)(x / 50)] == '1' 
	&& data->map[(int)(y / 50)][(int)(x - dx) / 50] == '1')
		return (0);
	return (1);
}

int	walls_checker3(double x, double y, float dy, float dx, t_data *data)
{
	if (data->map[(int)(y + dy) / 50][(int)(x / 50)] == '1')
		return ('y');
	if (data->map[(int)(y / 50)][(int)(x + dx) / 50] == '1')
		return ('x');
	if (data->map[(int)(y + dy) / 50][(int)(x + dx) / 50] == '1')
		return (1);
	return (0);
}