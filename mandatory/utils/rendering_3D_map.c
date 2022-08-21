/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_3D_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:23:52 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/21 13:55:04 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rendering_3d_map(t_data *data)
{
	double	rays[RSX];

	rays_counter(data, rays);
	put_black_background(data);
	rays_to_image(data, rays);
}
