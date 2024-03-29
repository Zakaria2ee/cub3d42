/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:28:11 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/27 20:32:34 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_clear_window(data->mlx, data->mlx_win),
		ft_exit("Exit\n");
	}
	else if (keycode == 13)
		move_stright(data);
	else if (keycode == 123)
		look_left(data);
	else if (keycode == 124)
		look_right(data);
	else if (keycode == 1)
		move_back(data);
	else if (keycode == 0)
		move_left(data);
	else if (keycode == 2)
		move_right(data);
	rendering_3d_map(data);
	return (0);
}
