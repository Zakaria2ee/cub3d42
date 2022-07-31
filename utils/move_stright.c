/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stright.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:01:42 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/31 12:04:36 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void move_stright(t_data *data)
{
    if(!walls_checker3(data->player_x, data->player_y, PX * sin(data->player_a * PI/180), PX * cos(data->player_a * PI/180), data))
        return ;
    data->player_x += PX * cos(data->player_a * PI/180);
    data->player_y += PX * sin(data->player_a * PI/180);
}