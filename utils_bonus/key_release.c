/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:09:52 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/08 16:38:54 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int add_key_release(int keycode, t_data *data)
{
    if(keycode == 53)
        data->keys[0] = 0;
    else if (keycode == 13)
        data->keys[1] = 0;
    else if(keycode == 123)
        data->keys[2] = 0;
    else if(keycode == 124)
        data->keys[3] = 0;
    else if(keycode == 1)
        data->keys[4] = 0;
    else if(keycode == 0)
        data->keys[5] = 0;
    else if(keycode == 2)
        data->keys[6] = 0;
    else if (keycode == 49)
        data->keys[7] = 0;
    return (0);
}