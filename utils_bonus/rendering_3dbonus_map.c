/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_3dbonus_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:55:25 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/07 15:03:23 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void rendering_3dbonus_map(t_data *data)
{
    double rays[RSX];

    rays_counter_b(data, rays);
    put_black_background(data);
    rays_to_image_b(data, rays);
}