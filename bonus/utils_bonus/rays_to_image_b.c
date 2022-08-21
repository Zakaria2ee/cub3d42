/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_to_image_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:48:59 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/21 11:57:44 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_floor(t_data *data, int *v, t_img img, int *i);

void	rays_to_image_b(t_data *data, double *rays)
{
	int	current_y;

	current_y = RSY - 1;
	data->current_x = 0;
	while (data->current_x < RSX)
	{
		put_pixles_b(data->screen, rays, data);
		data->current_x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->screen.mlx_img, 0, 0);
}

double	distance(int x, int y, int x1, int y1)
{
	return (sqrt(((x - x1) * (x - x1))
			+ ((y - y1) * (y - y1))));
}

void	put_pixles_b(t_img img, double *rays, t_data *data)
{
	int	i;
	int	v;
	int	to_draw;

	v = 0;
	data->current_y = RSY - 1;
	i = (RSY - (RSY * 50 / rays[data->current_x])) / 2;
	to_draw = i;
	draw_floor(data, &v, img, &i);
	i = (RSY * 50 / rays[data->current_x]);
	to_draw = i;
	if (i > RSY)
		i -= (i - RSY) / 2;
	while (i >= 0 && data->current_y > 0)
	{
		data->t_color = get_color_b(data, data->dirray[data->current_x],
				(int)((float)((float)TEXY / (float)to_draw) *(float)i) % TEXY,
				rays[data->current_x]);
		ft_put_pxl(&img, data->current_x, data->current_y, data->t_color);
		i--;
		data->current_y--;
	}
	draw_sky(data, img);
}

void	draw_sky(t_data *data, t_img img)
{
	while (data->current_y >= 0)
	{
		if (data->current_y > 255)
			data->t_color = 255;
		else
			data->t_color = data->current_y ;
		ft_put_pxl(&img, data->current_x, data->current_y,
			data->sky + ((unsigned char)data->t_color << 24));
		data->current_y--;
	}
}

void	draw_floor(t_data *data, int *v, t_img img, int *i)
{
	while (*i > 0)
	{
		if (((distance(data->current_x, data->current_y,
						RSX / 2, RSY) - data->current_y - 100) / 8) > 0)
			*v = 1;
		if (!*v)
			ft_put_pxl(&img, data->current_x, data->current_y, data->floor
				+ ((unsigned char)((distance(data->current_x,
								data->current_y, RSX / 2, RSY)
							- data->current_y - 150) / 8) << 24));
		else
			ft_put_pxl(&img, data->current_x, data->current_y, 0x000000);
		data->current_y--;
		(*i)--;
	}
}
