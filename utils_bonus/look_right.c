/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:52:00 by mabenchi          #+#    #+#             */
/*   Updated: 2022/08/14 14:52:19 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	look_right(t_data *data)
{
	data->player_a += RA;
	data->player_a = data->player_a % 360;
	rendering_3dbonus_map(data);
	mini_map(data);
}
