/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_key_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:56:38 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/14 14:37:03 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	render_map(t_data *data)
{
	usleep(150 * 200);
	if (data->keys[0] == 1)
		ft_exit("Exit\n");
	if (data->keys[1] == 1)
		move_stright_b(data);
	if (data->keys[2] == 1)
		look_left(data);
	if (data->keys[3] == 1)
		look_right(data);
	if (data->keys[4] == 1)
		move_back_b(data);
	if (data->keys[5] == 1)
		move_left(data);
	if (data->keys[6] == 1)
		move_right(data);
	if (data->keys[7] == 1)
		open_door(data);
	close_door(data);
	return (0);
}