/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:48:59 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/03 09:53:23 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void rays_to_image(t_data *data, double *rays, int *dirRay)
{
    int current_y;
    int current_x;
    t_img img;

    (void)dirRay;
    img.mlx_img = mlx_new_image(data->mlx, RSX, RSY);
    img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);
    current_y = RSY - 1;
    current_x = 0;
    while(current_x < 1200)
    {
        put_pixles(img, current_x, rays, dirRay, data);
        current_x++;
    }
    mlx_put_image_to_window(data->mlx, data->mlx_win, img.mlx_img, 0,0);
}

int get_color(t_data *data, int x, int y, int d, int dirRay)
{
    int pixel;

    if (d > 150)
        d = 150;
        x = 0;
        y = 0;
        (void)data;
    //pixel = NULL;
    if (dirRay == 's')
        // pixel = data->s.addr + (y * data->s.line_len + x * (data->s.bpp / 8));
        pixel = 0xFFFFFF;
    else if (dirRay == 'w')
        pixel = 0xFF0000;
    else if (dirRay == 'n')
        pixel = 0x00FF00;
    else
        pixel = 0x0000FF;
    return ((pixel) + (((unsigned char)d) << 24));
}

void put_pixles(t_img img, int current_x, double *rays, int *dirRay, t_data *data)
{
    int i;
    int color;
    int current_y;

    current_y = RSY - 1;
    i = (RSY - (RSY * 50/rays[current_x]))/2;
    while(i > 0)
    {
        ft_put_pxl(&img, current_x, current_y, data->Floor);
        current_y--;
        i--;
    }
    i = RSY * 50/rays[current_x];
    if(i > RSY)
        i = RSY - 1;
    while (i >= 0 && current_y > 0)
    {
        color = get_color(data, 0, 0, rays[current_x], dirRay[current_x]);
        ft_put_pxl(&img, current_x, current_y, color);
        i--;
        current_y--;
    }
    while(current_y >= 0)
    {
        ft_put_pxl(&img, current_x, current_y, data->Sky);
        current_y--;
    }
}

void ft_put_pxl(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}