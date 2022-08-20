/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:25:03 by mabenchi          #+#    #+#             */
/*   Updated: 2022/08/20 15:04:20 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void if_condi(t_data *data);

void	check_doors(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i && data->map[i])
	{
		j = -1;
		while (++j && data->map[i][j])
		{
			if (data->map[i][j] == 'D')
			{
				if ((j && data->map[i][j - 1] != '1')
					|| ((size_t)(j + 1) < ft_strlen(data->map[i])
					&& data->map[i][j + 1] != '1'))
				{
					if ((i && data->map[i - 1][j] != '1')
					|| (data->map[i + 1] && data->map[i + 1][j] != '1'))
						ft_exit("ERROR\nA DOOR SHOULD BE BETWEEN WALLS\n");
				}
			}
		}
	}
}

void	open_door(t_data *data)
{
	if (data->map[(int)(data->player_y / 50) - 1][(int)(data->player_x / 50)] == 'D'
		&& data->player_a > 180 && data->player_a < 360)
	{
		data->map[(int)(data->player_y / 50) - 1][(int)(data->player_x / 50)] = '9';
		data->opened_door = 1;
	}
	else if (data->map[(int)(data->player_y / 50) + 1][(int)(data->player_x / 50)] == 'D'
		&& data->player_a > 0 && data->player_a < 180)
	{
		data->map[(int)(data->player_y / 50) + 1][(int)(data->player_x / 50)] = '9';
		data->opened_door = 2;
	}
	if_condi(data);
	rendering_3dbonus_map(data);
	mini_map(data);
}

void	close_door(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->line && data->map[i])
	{
		j = 0;
		while ((size_t)j < ft_strlen(data->map[i]))
		{
			if (data->map[i][j] == '9'
				&& distance(j * 50, i * 50,
					data->player_x, data->player_y) > 100)
				data->map[i][j] = 'D';
			j++;
		}
		i++;
	}
}

void if_condi(t_data *data)
{
	if (data->map[(int)(data->player_y / 50)][(int)(data->player_x / 50) - 1] == 'D'
		&& (data->player_a > 90 && data->player_a < 270))
	{
		data->map[(int)(data->player_y / 50)][(int)(data->player_x / 50) - 1] = '9';
		data->opened_door = 3;
	}
	else if (data->map[(int)(data->player_y / 50)][(int)(data->player_x / 50) + 1] == 'D'
		&& (data->player_a > 270 || data->player_a < 90))
	{
		data->map[(int)(data->player_y / 50)][(int)(data->player_x / 50) + 1] = '9';
		data->opened_door = 4;
	}
}