/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:50:44 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/01 09:12:02 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void render_2dmap(t_data *data)
{
    //float x;
    //float r;
    int i;
    //float y;
    float angle;
    int j;
    int jj;
    int xx;

    i = 0;
    angle = data->player_a - 30;
    //r = -30;
    i = (data->player_x - 100)/50;
    xx = data->line - 5;
    while(data->map[i])
    {
        j = (data->player_y - 100)/50;
        jj = data->column - 5;
        while(data->map[i][j])
        {
            if(data->map[i][j] == '0')
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2, jj * 50 , xx * 50);
            if(data->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->img1, jj * 50 , xx * 50);
            jj++;
            j++;
        }
        xx++;
        i++;
    }
    // while(r < 30)
    // { 
    //     if(angle >= 360)
    //         angle -= 360;
    //     else if(angle < 0)
    //         angle += 360;
        
    //     x = data->player_x;
    //     y = data->player_y;
    //     while(walls_checker3(x, y, 1 * sin(angle * PI/180),  1 * cos(angle * PI/180), data))
    //     {
    //         x += 1 * cos(angle * PI/180);
    //         y += 1 * sin(angle * PI/180);
    //         mlx_pixel_put(data->mlx, data->mlx_win, x,  y, 0xFF4500);
    //     }
    //     angle += 0.05;
    //     r += 0.05;
    //     i++;
    // }
}