/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:58:15 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/25 08:58:59 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	if (walls_checker310(data->player_x, data->player_y, angle, data))
		return ;
	data->player_x += 10 * cos(angle * PI / 180);
	data->player_y += 10 * sin(angle * PI / 180);
	rendering_3d_map(data);
}
