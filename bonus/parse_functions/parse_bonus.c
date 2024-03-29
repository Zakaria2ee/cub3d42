/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:34:44 by mabenchi          #+#    #+#             */
/*   Updated: 2022/08/24 11:41:47 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	parsing_b(char **argv, t_data *data)
{
	init2(data);
	check_extention(argv[1]);
	get_textures(argv, data);
	get_map(data);
	error_handler(data);
	check_doors(data);
	get_player_a(data);
	return (0);
}

void	init2(t_data *data)
{
	data->east = 0;
	data->west = 0;
	data->south = 0;
	data->north = 0;
}
