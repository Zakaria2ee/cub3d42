/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:03:19 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/31 12:11:46 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void move_back(t_data *data)
{
    if(!walls_checker2(data->player_x, data->player_y,  PX * sin(data->player_a * PI/180), PX * cos(data->player_a * PI/180), data))
        return ;
    data->player_x -= PX * cos(data->player_a * PI/180);
    data->player_y -= PX * sin(data->player_a * PI/180);
}