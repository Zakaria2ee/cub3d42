/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 09:49:54 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/30 19:41:28 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void rendering(t_data *data)
{
    data->mlx = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx, RSX,  RSY, "Cub3d"); 
    init(data);
    rendering_3d_map(data);
    mlx_hook(data->mlx_win, 17, 1, &ft_close, 0);  
    mlx_hook(data->mlx_win,2 ,0 ,  &key_hook ,data);
    //mlx_hook(data->mlx_win, 6, 0L, mouse_pos, data);   
    //mlx_loop_hook(data->mlx, set_windows, data);
   
    mlx_loop(data->mlx);
}



// int mouse_pos(int x, int y, t_data *data)
// {
//     (void)data;

//     printf("(x,y)(%d,%d)\n", x,y);
//     return (0);
// }


void init(t_data *data)
{
    data->img1 = mlx_xpm_file_to_image(data->mlx, "img/space.xpm", &data->h, &data->w);
    data->img2 = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm", &data->h, &data->w);
    data->player_dx = cos(data->player_a * PI/180) * PX;
    data->player_dy = sin(data->player_a * PI/180) * PX;
}