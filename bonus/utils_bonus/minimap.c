/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:50:44 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/21 13:48:49 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	drawcircle(t_data *data, float x, float y, int w)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < w && x + i < 200)
	{
		j = 0;
		while (j < w && y + j < 200)
		{
			if (sqrt(((x + (w / 2) - (x + i)) * (x + (w / 2) - (x + i)))
					+ ((y + (w / 2) - (y + j)) * (y + (w / 2) - (y + j)))) < 5)
				ft_put_pxl(&(data->minimap), x + i, y + j, 0x000000);
			j++;
		}
		i++;
	}
	i = -1;
	while (++i < w && x + 15 + i < 200)
	{
		ft_put_pxl(&(data->minimap), x + 15, y + 15, 0xFF0000);
		x += cos(data->player_a * PI / 180);
		y += sin(data->player_a * PI / 180);
	}
}

static void	draw_outside_map_norm(t_data *data, int *j, int f_j)
{
	int	k;
	int	z;

	k = 0;
	z = 0;
	while (k < 200)
	{
		*j = f_j;
		z = 0;
		while (*j < 0 && z < 200)
		{
			if (!in_circle(z, k, 200))
				ft_put_pxl(&(data->minimap), k, z, 0xFF000000);
			else
				ft_put_pxl(&(data->minimap), k, z, 0x000000);
			z++;
			(*j)++;
		}
		k++;
	}
}

static void	draw_outside_map(t_data *data, int *i, int *j, int f_j)
{
	int	k;
	int	z;

	k = 0;
	z = 0;
	while (*i < 0 && z < 200)
	{
		k = 0;
		while (k < 200)
		{
			if (!in_circle(z, k, 200))
				ft_put_pxl(&(data->minimap), z, k, 0xFF000000);
			else
				ft_put_pxl(&(data->minimap), z, k, 0x000000);
			k++;
		}
		z++;
		(*i)++;
	}
	draw_outside_map_norm(data, j, f_j);
}

static void	put_map(t_data *data, int i, int j)
{
	int	f_i;
	int	f_j;

	f_i = data->player_x - 100;
	f_j = data->player_y - 100;
	if (!in_circle(i - f_i, j - f_j, 200))
		ft_put_pxl(&(data->minimap), i - f_i, j - f_j, 0xFF000000);
	else if ((size_t)(i / 50) < ft_strlen(data->map[(int)(j / 50)])
		&& data->map[(int)(j / 50)][(int)(i / 50)] == '0')
		ft_put_pxl(&(data->minimap), i - f_i, j - f_j, 0xFFFFFF);
	else if ((size_t)(i / 50) < ft_strlen(data->map[(int)(j / 50)])
			&& data->map[(int)(j / 50)][(int)(i / 50)] == '1')
		ft_put_pxl(&(data->minimap), i - f_i, j - f_j, 0x000000);
	else
		ft_put_pxl(&(data->minimap), i - f_i, j - f_j, 0xF0F0FF);
}

void	mini_map(t_data *data)
{
	int	i;
	int	j;
	int	f_i;
	int	f_j;
	int	k;

	i = data->player_x - 100;
	f_i = i;
	j = data->player_y - 100;
	f_j = j;
	draw_outside_map(data, &i, &j, f_j);
	k = i;
	while ((int)(j / 50) < data->line
			&& (j - f_j) < 200 && j >= 0 && data->map[(int)(j / 50)])
	{
		i = k;
		while ((i - f_i) < 200
			&& (size_t)(i / 50) < ft_strlen(data->map[(int)(j / 50)])
				&& i >= 0 && data->map[(int)(j / 50)][(int)(i / 50)])
			put_map(data, i++, j);
		j++;
	}
	drawcircle(data, 85, 85, 30);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->minimap.mlx_img, 1000, 600);
}
