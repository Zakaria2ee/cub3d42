/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_3dbonus_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:55:25 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/16 12:24:28 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	rendering_3dbonus_map(t_data *data)
{
	double	rays[RSX];

	rays_counter_b(data, rays);
	put_black_background(data);
	rays_to_image_b(data, rays);
}
