/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_to_image_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:48:59 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/14 16:04:44 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	put_pixles_b(t_img img, int current_x, double *rays, t_data *data);

void	rays_to_image_b(t_data *data, double *rays)
{
	int	current_y;
	int	current_x;

	current_y = RSY - 1;
	current_x = 0;
	while (current_x < RSX)
	{
		put_pixles_b(data->screen, current_x, rays, data);
		current_x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->screen.mlx_img, 0, 0);
}

static int	get_color_b(t_data *data, int *dirRay, int y, int d)
{
	int	pixel;

	if (d > 180)
		d = 180;
	if (dirRay[2] == 'D')
		pixel = (*(int *)(data->door.addr + (y * data->door.line_len
						+ dirRay[1] * (data->door.bpp / 8))));
	else if (dirRay[0] == 's')
		pixel = (*(int *)(data->s.addr + (y * data->s.line_len
						+ dirRay[1] * (data->s.bpp / 8))));
	else if (dirRay[0] == 'w')
		pixel = (*(int *)(data->we.addr + (y * data->we.line_len
						+ dirRay[1] * (data->we.bpp / 8))));
	else if (dirRay[0] == 'n')
		pixel = (*(int *)(data->n.addr + (y * data->n.line_len
						+ dirRay[1] * (data->n.bpp / 8))));
	else
		pixel = (*(int *)(data->e.addr + (y * data->e.line_len
						+ dirRay[1] * (data->e.bpp / 8))));
	return (pixel + ((unsigned char)d << 24));
}

double	distance(int x, int y, int x1, int y1)
{
	return (sqrt(((x - x1) * (x - x1))
			+ ((y - y1) * (y - y1))));
}

void	put_pixles_b(t_img img, int current_x, double *rays,  t_data *data)
{
	int	i;
	int	v;
	int	color;
	int	current_y;
	int	to_draw;

	v = 0;
	current_y = RSY - 1;
	i = (RSY - (RSY * 50 / rays[current_x])) / 2;
	to_draw = i;
	while (i > 0)
	{
		if (((distance(current_x, current_y,
						RSX / 2, RSY) - current_y - 100) / 8) > 0)
			v = 1;
		if (!v)
			ft_put_pxl(&img, current_x, current_y, data->Floor
				+ ((unsigned char)((distance(current_x, current_y, RSX / 2, RSY)
							- current_y - 150) / 8) << 24));
		else
			ft_put_pxl(&img, current_x, current_y, 0x000000);
		current_y--;
		i--;
	}
	i = (RSY * 50 / rays[current_x]);
	to_draw = i;
	if (i > RSY)
		i -= (i - RSY) / 2;
	while (i >= 0 && current_y > 0)
	{
		color = get_color_b(data, data->dirRay[current_x],
				(int)((float)((float)TEXY / (float)to_draw) *(float)i) % TEXY,
				rays[current_x]);
		ft_put_pxl(&img, current_x, current_y, color);
		i--;
		current_y--;
	}
	while (current_y >= 0)
	{
		if (current_y > 255)
			color = 255;
		else
			color = current_y ;
		ft_put_pxl(&img, current_x, current_y,
			data->Sky + ((unsigned char)color << 24));
		current_y--;
	}
}
