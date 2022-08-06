/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stright.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:01:42 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/06 14:52:17 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void move_stright(t_data *data)
{
    if(walls_checker3(data->player_x, data->player_y, 20 * sin(data->player_a * PI/180), 20 * cos(data->player_a * PI/180), data))
    {
        if(data->map[data->player_y/50][(data->player_x + (int)round(PX * cos(data->player_a * PI/180)))/50] != '1')
        {
            if(data->player_a <= 200 && data->player_a > 180)
                data->player_x += round(PX * cos(data->player_a * PI/180));
            else if(data->player_a >= 340 && data->player_a < 360)
                data->player_x += round(PX * cos(data->player_a * PI/180));
            else if(data->player_a <= 20 && data->player_a > 0)
                data->player_x += round(PX * cos(data->player_a * PI/180));
            else if(data->player_a >= 160 && data->player_a < 180)
                data->player_x += round(PX * cos(data->player_a * PI/180));
            printf("Af\n");
        }
        if(data->map[(data->player_y + (int)round(PX * sin(data->player_a * PI/180)))/50][data->player_x/50] != '1')
        {
            if(data->player_a <= 110 && data->player_a > 90)
                data->player_y += round(PX * sin(data->player_a * PI/180));
            else if(data->player_a >= 250 && data->player_a < 270)
                data->player_y += round(PX * sin(data->player_a * PI/180)); 
            else if(data->player_a <= 290 && data->player_a > 270)
                data->player_y += round(PX * sin(data->player_a * PI/180)); 
            else if(data->player_a >= 70 && data->player_a < 90)
                data->player_y += round(PX * sin(data->player_a * PI/180)); 
            printf("af\n");
        }
        else
            return ;
    }
    else if(!walls_checker3(data->player_x, data->player_y, 20 * sin(data->player_a * PI/180), 20 * cos(data->player_a * PI/180), data))
    {
        data->player_x += round(PX * cos(data->player_a * PI/180));
        data->player_y += round(PX * sin(data->player_a * PI/180));
    }
}