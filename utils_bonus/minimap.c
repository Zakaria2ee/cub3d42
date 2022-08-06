/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:50:44 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/06 18:06:47 by mabenchi         ###   ########.fr       */
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

static void draw_plus(t_data *data, int *i, int *j, int f_j)
{
    int k;
    int z;

    k = 0;
    z = 0;
    while (*i < 0 && z < 200)
    {
        k = 0;
        while (k < 200)
        {
            ft_put_pxl(&(data->img1), z, k, 0x000000);
            k++;
        }
        z++;
        (*i)++;
    }
    k = 0;
    z = 0;
    while (k < 200)
    {
        *j = f_j;
        z = 0;
        while (*j < 0 && z < 200)
        {
            ft_put_pxl(&(data->img1), k, z, 0x000000);
            z++;
            (*j)++;
        }
        k++;
    }
}

void mini_map(t_data *data)
{
    int i;
    int j;
    int f_i;
    int f_j;
    float angle;
    int k;

    angle = data->player_a - 30;
    i = data->player_x - 100;
    f_i = i;
    j = data->player_y - 100;
    f_j = j;
    draw_plus(data, &i, &j, f_j);
    k = i;
    while ((j - f_j - 1) < 200 && j >= 0 && data->map[(int)(j / 50)])
    {
        i = k;
        while ((i - f_i - 1) < 200 && i >= 0 && data->map[(int)(j / 50)][(int)(i / 50)])
        {
            if ((int)(j / 50) < data->line && (size_t)(i / 50) < ft_strlen(data->map[(int)(j / 50)]) && data->map[(int)(j / 50)][(int)(i / 50)] == '0')
                ft_put_pxl(&(data->img1), (i - f_i) % 200, (j - f_j) % 200, 0xFFFFFF);
            else if ((int)(j / 50) < data->line && (size_t)(i / 50) < ft_strlen(data->map[(int)(j / 50)]) && data->map[(int)(j / 50)][(int)(i / 50)] == '1')
                ft_put_pxl(&(data->img1), (i - f_i) % 200, (j - f_j) % 200, 0x000000);
            else
                ft_put_pxl(&(data->img1), (i - f_i) % 200, (j - f_j) % 200, 0xFF00FF);
            i++;
        }
        j++;
    }
    drawcircle(data, 85, 85, 30, 0x000000);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img1.mlx_img, 0,0);
}