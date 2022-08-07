/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_key_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:56:38 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/07 21:47:52 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int bonus_key_hook(int keycode, t_data *data)
{
    if(keycode == 53)
        ft_exit("Exit\n");
    else if (keycode == 13)
        move_stright_b(data);
    else if(keycode == 123)
        look_left(data);
    else if(keycode == 124)
        look_right(data);
    else if(keycode == 1)
        move_back_b(data);
    else if(keycode == 0)
        move_left(data);
    else if(keycode == 2)
        move_right(data);
    else if (keycode == 49)
        open_door(data);
    rendering_3dbonus_map(data);
    mini_map(data);
    return (0);
}