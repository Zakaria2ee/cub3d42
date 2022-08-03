/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stright.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:01:42 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/02 16:16:16 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void move_stright(t_data *data)
{
    if(walls_checker3(data->player_x, data->player_y, PX * sin(data->player_a * PI/180), PX * cos(data->player_a * PI/180), data))
        return ;
    data->player_x += round(PX * cos(data->player_a * PI/180));
    data->player_y += round(PX * sin(data->player_a * PI/180));
}