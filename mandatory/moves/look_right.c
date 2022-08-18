/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:18:54 by mabenchi          #+#    #+#             */
/*   Updated: 2022/08/16 13:30:19 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	look_right(t_data *data)
{
	data->player_a += RA;
	data->player_a = data->player_a % 360;
	rendering_3d_map(data);
}
