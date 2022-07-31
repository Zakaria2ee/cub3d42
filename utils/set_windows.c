/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_windows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:48:12 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/30 14:52:51 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int set_windows(t_data *data)
{
    if(data->player_a < 360 && data->player_a > 180)
        data->color = 0x800000;
    else if(data->player_a < 270 && data->player_a > 90)
        data->color = 0xFF6347;
    else if(data->player_a < 180 && data->player_a > 0)
        data->color = 0xFF4500;
    else if(data->player_a < 90 && data->player_a > 270)
        data->color = 0xDB7093;
    //rays_counter(data);
    //render_2dmap(data);
    return (0);
}