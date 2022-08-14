/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stright.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:01:42 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/14 16:14:33 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_stright(t_data *data)
{
	if (!walls_checker3(data->player_x,
			data->player_y, 20 * sin(data->player_a * PI / 180),
			20 * cos(data->player_a * PI / 180), data))
	{
		data->player_x += round(PX * cos(data->player_a * PI / 180));
		data->player_y += round(PX * sin(data->player_a * PI / 180));
	}
	rendering_3d_map(data);
}
