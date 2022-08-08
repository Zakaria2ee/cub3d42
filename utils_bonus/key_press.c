/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:09:54 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/08 16:17:45 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int add_key_press(int keycode, t_data *data)
{
    if(keycode == 53)
        data->keys[0] = 1;
    else if (keycode == 13)
        data->keys[1] = 1;
    else if(keycode == 123)
        data->keys[2] = 1;
    else if(keycode == 124)
        data->keys[3] = 1;
    else if(keycode == 1)
        data->keys[4] = 1;
    else if(keycode == 0)
        data->keys[5] = 1;
    else if(keycode == 2)
        data->keys[6] = 1;
    else if (keycode == 49)
        data->keys[7] = 1;
    return (0);
}