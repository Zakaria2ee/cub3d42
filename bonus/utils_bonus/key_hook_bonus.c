/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:56:38 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/27 20:31:16 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	render_map(t_data *data)
{
	usleep(200 * 200);
	if (data->keys[0] == 1)
	{
		mlx_clear_window(data->mlx, data->mlx_win),
		ft_exit("Exit\n");
	}
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
