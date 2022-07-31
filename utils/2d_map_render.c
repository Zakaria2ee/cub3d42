/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:50:44 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/30 16:39:36 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void render_2dmap(t_data *data)
{
    float x;
    int i;
    float r;
    float y;
    float angle;
    int j;

    i = 0;
    angle = data->player_a - 30;
    r = -30;
    i = data->column - 5;
    while(data->map[i])
    {
        j = data->line - 10;
        while(data->map[i][j])
        {
            if(data->map[i][j] == '0')
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2, j * 50 , i * 50);
            if(data->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->img1, j * 50 , i * 50);
            j++;
        }
        i++;
    }
    while(r < 30)
    { 
        if(angle >= 360)
            angle -= 360;
        else if(angle < 0)
            angle += 360;
        
        x = data->player_x;
        y = data->player_y;
        while(walls_checker3(x, y, 1 * sin(angle * PI/180),  1 * cos(angle * PI/180), data))
        {
            x += 1 * cos(angle * PI/180);
            y += 1 * sin(angle * PI/180);
            mlx_pixel_put(data->mlx, data->mlx_win, x,  y, 0xFF4500);
        }
        angle += 0.05;
        r += 0.05;
        i++;
        }
}