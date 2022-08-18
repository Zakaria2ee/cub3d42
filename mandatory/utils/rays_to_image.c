/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:48:59 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/16 13:30:03 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rays_to_image(t_data *data, double *rays)
{
	int		current_y;
	int		current_x;
	t_img	img;

	img.mlx_img = mlx_new_image(data->mlx, RSX, RSY);
	img.addr = mlx_get_data_addr(img.mlx_img,
			&img.bpp, &img.line_len, &img.endian);
	current_y = RSY - 1;
	current_x = 0;
	while (current_x < RSX)
	{
		put_pixles(img, current_x, rays, data);
		current_x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, img.mlx_img, 0,0);
}

static int	get_color(t_data *data, int *dirray, int y, int d)
{
	int	pixel;

	if (d > 200)
		d = 200;
	if (dirray[0] == 's')
		pixel = (*(int *)(data->s.addr
					+ (y * data->s.line_len
						+ dirray[1] * (data->s.bpp / 8))));
	else if (dirray[0] == 'w')
		pixel = (*(int *)(data->we.addr
					+ (y * data->we.line_len
						+ dirray[1] * (data->we.bpp / 8))));
	else if (dirray[0] == 'n')
		pixel = (*(int *)(data->n.addr
					+ (y * data->n.line_len
						+ dirray[1] * (data->n.bpp / 8))));
	else
		pixel = (*(int *)(data->e.addr
					+ (y * data->e.line_len
						+ dirray[1] * (data->e.bpp / 8))));
	return (pixel + ((unsigned char)d << 24));
}

void	put_pixles(t_img img, int current_x, double *rays,  t_data *data)
{
	int	i;
	int	color;
	int	current_y;
	int	to_draw;

	current_y = RSY - 1;
	i = (RSY - (RSY * 50 / rays[current_x])) / 2;
	while (i > 0)
	{
		ft_put_pxl(&img, current_x, current_y, data->floor);
		current_y--;
		i--;
	}
	i = (RSY * 50 / rays[current_x]);
	to_draw = i;
	if (i > RSY)
		i -= (i - RSY) / 2;
	while (i >= 0 && current_y > 0)
	{
		color = get_color(data, data->dirray[current_x],
				(int)((float)((float)TEXY / (float)to_draw)
					*(float)i) % TEXY, rays[current_x]);
		ft_put_pxl(&img, current_x, current_y, color);
		i--;
		current_y--;
	}
	while (current_y >= 0)
	{
		ft_put_pxl(&img, current_x, current_y, data->sky);
		current_y--;
	}
}
