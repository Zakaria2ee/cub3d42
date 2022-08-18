/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_black_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:58:16 by mabenchi          #+#    #+#             */
/*   Updated: 2022/08/16 13:30:07 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_black_background(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->black.mlx_img, 0,0);
}

void	put_black_pixel(t_data *data)
{
	int	current_y;
	int	current_x;

	current_y = RSY - 1;
	current_x = 0;
	while (current_x < RSX)
	{
		current_y = RSY - 1;
		while (current_y >= 0)
		{
			ft_put_pxl(&(data->black), current_x, current_y, 0x000000);
			current_y--;
		}
		current_x++;
	}
}
