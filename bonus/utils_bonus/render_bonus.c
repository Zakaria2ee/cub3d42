/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 09:49:54 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/27 12:21:33 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	rendering_bonus(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, RSX, RSY, "Cub3d");
	init(data);
	rendering_3dbonus_map(data);
	mini_map(data);
	mlx_hook(data->mlx_win, 17, 1, ft_close, 0);
	mlx_hook(data->mlx_win, 2, 1L << 0, add_key_press, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, add_key_release, data);
	mlx_loop_hook(data->mlx, render_map, data);
	mlx_loop(data->mlx);
}

void	init(t_data *data)
{
	data->screen.mlx_img = mlx_new_image(data->mlx, RSX, RSY);
	data->screen.addr = mlx_get_data_addr(data->screen.mlx_img,
			&data->screen.bpp, &data->screen.line_len, &data->screen.endian);
	data->minimap.mlx_img = mlx_new_image(data->mlx, 200, 200);
	data->minimap.addr = mlx_get_data_addr(data->minimap.mlx_img,
			&data->minimap.bpp, &data->minimap.line_len, &data->minimap.endian);
	data->door.mlx_img = mlx_xpm_file_to_image(data->mlx,
			"../textures/door.xpm", &data->door.w, &data->door.h);
	data->door.addr = mlx_get_data_addr(data->door.mlx_img, &data->door.bpp,
			&data->door.line_len, &data->door.endian);
	data->e.mlx_img = mlx_xpm_file_to_image(data->mlx, data->east,
			&data->e.w, &data->e.h);
	data->e.addr = mlx_get_data_addr(data->e.mlx_img, &data->e.bpp,
			&data->e.line_len, &data->e.endian);
	data->we.mlx_img = mlx_xpm_file_to_image(data->mlx, data->west,
			&data->we.w, &data->we.h);
	init1(data);
}

void	init1(t_data *data)
{
	int	i;

	i = -1;
	data->we.addr = mlx_get_data_addr(data->we.mlx_img, &data->we.bpp,
			&data->we.line_len, &data->we.endian);
	data->s.mlx_img = mlx_xpm_file_to_image(data->mlx, data->south,
			&data->s.w, &data->s.h);
	data->s.addr = mlx_get_data_addr(data->s.mlx_img, &data->s.bpp,
			&data->s.line_len, &data->s.endian);
	data->n.mlx_img = mlx_xpm_file_to_image(data->mlx, data->north,
			&data->n.w, &data->n.h);
	data->n.addr = mlx_get_data_addr(data->n.mlx_img, &data->n.bpp,
			&data->n.line_len, &data->n.endian);
	data->black.mlx_img = mlx_new_image(data->mlx, RSX, RSY);
	data->black.addr = mlx_get_data_addr(data->black.mlx_img, &data->black.bpp,
			&data->black.line_len, &data->black.endian);
	put_black_pixel(data);
	data->player_dx = cos(data->player_a * PI / 180) * PX;
	data->player_dy = sin(data->player_a * PI / 180) * PX;
	while (++i < 8)
		data->keys[i] = 0;
}

double	distance(int x, int y, int x1, int y1)
{
	return (sqrt(((x - x1) * (x - x1))
			+ ((y - y1) * (y - y1))));
}
