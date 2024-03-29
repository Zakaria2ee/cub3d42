/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 09:49:54 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/27 20:33:04 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rendering(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_exit("The mlx structure didn't inisialized\n");
	data->mlx_win = mlx_new_window(data->mlx, RSX, RSY, "Cub3d");
	init(data);
	rendering_3d_map(data);
	mlx_hook(data->mlx_win, 17, 1, &ft_close, data);
	mlx_hook(data->mlx_win, 2, 0, &key_hook, data);
	mlx_loop(data->mlx);
}

void	init(t_data *data)
{
	data->e.mlx_img = mlx_xpm_file_to_image(data->mlx, data->east,
			&data->e.w, &data->e.h);
	data->e.addr = mlx_get_data_addr(data->e.mlx_img, &data->e.bpp,
			&data->e.line_len, &data->e.endian);
	data->we.mlx_img = mlx_xpm_file_to_image(data->mlx, data->west,
			&data->we.w, &data->we.h);
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
}
