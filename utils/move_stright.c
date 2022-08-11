/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stright.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:01:42 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/11 11:46:54 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void move_stright(t_data *data)
{
    if(walls_checker3(data->player_x, data->player_y, 20 * sin(data->player_a * PI/180), 20 * cos(data->player_a * PI/180), data))
    {
        if(data->map[data->player_y/50][(data->player_x + (int)round(PX * cos(data->player_a * PI/180)))/50] != '1')
        {
            if(data->player_a != 270 && data->player_a != 90)
                data->player_x += round(PX * cos(data->player_a * PI/180));
        }
        if(data->map[(data->player_y + (int)round(PX * sin(data->player_a * PI/180)))/50][data->player_x/50] != '1')
        {
            if(data->player_a != 0 && data->player_a != 180)
                data->player_y += round(PX * sin(data->player_a * PI/180));
         
        }
        else
            return ;
    }
    else if(!walls_checker3(data->player_x, data->player_y, 20 * sin(data->player_a * PI/180), 20 * cos(data->player_a * PI/180), data))
    {
        data->player_x += round(PX * cos(data->player_a * PI/180));
        data->player_y += round(PX * sin(data->player_a * PI/180));
    }
    rendering_3d_map(data);
}