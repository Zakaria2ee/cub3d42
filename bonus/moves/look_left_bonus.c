/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:55:42 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/16 12:23:54 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	look_left(t_data *data)
{
	data->player_a -= RA;
	if (data->player_a < 0)
		data->player_a += 360;
	rendering_3dbonus_map(data);
	mini_map(data);
}
