/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:48:59 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/01 14:46:30 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void rays_to_image(t_data *data, double *rays)
{
    int current_y;
    int current_x;
    t_img img;

    img.mlx_img = mlx_new_image(data->mlx, RSX, RSY);
    img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);
    current_y = RSY - 1;
    current_x = 0;
    while(current_x < 1200)
    {
        put_pixles(img, current_x, current_y, rays, data);
        current_x++;
    }
    mlx_put_image_to_window(data->mlx, data->mlx_win, img.mlx_img, 0,0);
}

int get_color(int d, int color, int limit)
{
    if (d > limit)
        d = limit;
    else if (d < 20)
        d = 0;
    color += ((unsigned char)d) << 24;
    return (color);
}

void put_pixles(t_img img, int current_x, int current_y, double *rays, t_data *data)
{
    int i;
    int color;

    i = (RSY - (RSY * 50/rays[current_x]))/2;
    while(i > 0)
    {
        color = get_color(RSY - current_y, data->Floor, 100);
        ft_put_pxl(&img, current_x, current_y, color);
        current_y--;
        i--;
    }
    i = RSY * 50/rays[current_x];
    if(i > RSY)
        i = RSY - 1;
    color = get_color(rays[current_x], 0xFFFFFF, 150);
    while(i >= 0 && current_y > 0)
    {
        ft_put_pxl(&img, current_x, current_y, color);
        i--;
        current_y--;
    }
    while(current_y >= 0)
    {
        color = get_color(current_y, data->Sky, 100);
        ft_put_pxl(&img, current_x, current_y, color);
        current_y--;
    }
}
void ft_put_pxl(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}