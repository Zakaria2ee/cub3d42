/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_black_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:58:16 by mabenchi          #+#    #+#             */
/*   Updated: 2022/08/01 14:02:59 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_black_background(t_data *data)
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
		ft_put_pxl(&img, current_x, current_y, 0x000000);
        //put_pixles(img, current_x, current_y, rays, data);
        current_x++;
    }
    mlx_put_image_to_window(data->mlx, data->mlx_win, img.mlx_img, 0,0);
}