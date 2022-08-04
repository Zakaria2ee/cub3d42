/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_key_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:56:38 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/04 12:59:39 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int bonus_key_hook(int keycode, t_data *data)
{
    if(keycode == 53)
        ft_exit("Exit\n");
    else if (keycode == 13)
        move_stright(data);
    else if(keycode == 123)
        look_left(data);
    else if(keycode == 124)
        look_right(data);
    else if(keycode == 1)
        move_back(data);
    else if(keycode == 0)
        move_left(data);
    else if(keycode == 2)
        move_right(data);
    rendering_3dbonus_map(data);
    printf("here\n");
    return (0);
}