/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:35:01 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/04 12:33:49 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void move_left(t_data *data)
{
    int angle;
    int x;
    int y;

    x = data->player_x;
    y = data->player_y;
    angle = data->player_a;
    angle -= 90;
    if(angle > 360)
        angle -= 360;
    if(angle < 0)
        angle += 360;
    if(walls_checker3(x,y, PX * sin(angle * PI/180), PX * cos(angle * PI/180), data))
        return ;
    data->player_x += PX * cos(angle * PI/180);
    data->player_y += PX * sin(angle * PI/180);
}