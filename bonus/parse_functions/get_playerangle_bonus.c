/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_playerangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:41:22 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/21 12:11:23 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_player_a(t_data *data)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			check_p(data, i, j, &counter);
			check_p2(data, i, j, &counter);
			j++;
		}
		i++;
	}
	if (counter != 1)
		ft_exit("Error\nyou need one player position to start\n");
}

void	check_p(t_data *data, int i, int j, int *counter)
{
	if (data->map[i][j] == 'N')
	{
		(*counter)++;
		data->player_a = 270;
	}
	else if (data->map[i][j] == 'S')
	{
		(*counter)++;
		data->player_a = 90;
	}
}

void	check_p2(t_data *data, int i, int j, int *counter)
{
	if (data->map[i][j] == 'E')
	{
		(*counter)++;
		data->player_a = 0;
	}
	else if (data->map[i][j] == 'W')
	{
		(*counter)++;
		data->player_a = 180;
	}
	if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
		|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
	{
		data->map[i][j] = '0';
	}
}
