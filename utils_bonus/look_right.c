 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:03:05 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/24 18:10:39 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void look_right(t_data *data)
{
    data->player_a += RA;
    data->player_a = data->player_a % 360;
    rendering_3dbonus_map(data);
    mini_map(data);
}