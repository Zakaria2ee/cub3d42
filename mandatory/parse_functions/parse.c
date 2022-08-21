/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:42:16 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/21 13:53:17 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parsing(char **argv, t_data *data)
{
	init1(data);
	check_extention(argv[1]);
	get_textures(argv, data);
	get_map(argv, data);
	error_handler(data);
	get_player_a(data);
	return (0);
}

void	init1(t_data *data)
{
	data->north = 0;
	data->west = 0;
	data->east = 0;
	data->south = 0;
	data->column = 0;
	data->line = 0;
}
