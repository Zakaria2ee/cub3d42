/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_3dbonus_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:55:25 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/04 12:59:01 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void rendering_3dbonus_map(t_data *data)
{
    double rays[RSX];

    rays_counter(data, rays);
    put_black_background(data);
    rays_to_image(data, rays);
}