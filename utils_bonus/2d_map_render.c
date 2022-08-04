/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:50:44 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/04 22:30:53 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    drawcircle(t_data *data, float x, float y, int w, int color)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < w && x + i < 200)
    {
        j = 0;
        while (j < w && y + j < 200)
        {
            if (sqrt(((x + (w / 2) - (x + i)) *  (x + (w / 2) - (x + i)))
            + ((y + (w / 2) - (y + j)) * (y + (w / 2) - (y + j)))) < 5)
                ft_put_pxl(&(data->img1), x + i, y + j, color);
            j++;
        }
        i++;
    }
}

void render_2dmap(t_data *data)
{
    int i;
    int j;
    int f_i;
    int f_j;
    float angle;

    angle = data->player_a - 30;
    i = data->player_x - 100;
    if (i <= 0)
        i = data->player_x;
    f_i = i;
    j = data->player_y - 100;
    if (j <= 0)
        j = data->player_x;
    f_j = j;
    while (data->map[(int)(j / 50)] && (i - f_i - 1) < 200)
    {
        j = f_j;
        while (data->map[(int)(j / 50)][(int)(i / 50)] && (j - f_j - 1) < 200)
        {
            if (data->map[(int)(j / 50)][(int)(i / 50)] == '0')
                ft_put_pxl(&(data->img1), (i - f_i) % 200, (j - f_j) % 200, 0xFFFFFF);
            else if (data->map[(int)(j / 50)][(int)(i / 50)] == '1')
                ft_put_pxl(&(data->img1), (i - f_i) % 200, (j - f_j) % 200, 0x000000);
            else
                ft_put_pxl(&(data->img1), (i - f_i) % 200, (j - f_j) % 200, 0xFF00FF);
            j++;
        }
        i++;
    }
    drawcircle(data, 100, 100, 30, 0x000000);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img1.mlx_img, 0,0);
}