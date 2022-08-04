/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:55:42 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/04 12:33:40 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void look_left(t_data *data)
{
    data->player_a -= RA;
    if(data->player_a < 0)
        data->player_a += 360;
}