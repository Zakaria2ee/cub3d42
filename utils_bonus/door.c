/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:25:03 by mabenchi          #+#    #+#             */
/*   Updated: 2022/08/08 16:32:49 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_strlennl(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	check_doors(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'D')
			{
				if ((j && data->map[i][j - 1] != '1')
					|| ((size_t)(j + 1) < ft_strlen(data->map[i]) && data->map[i][j + 1] != '1'))
				{
					if((i && data->map[i - 1][j] != '1')
					|| (data->map[i + 1] && data->map[i + 1][j] != '1'))
						ft_exit("ERROR\nA DOOR SHOULD BE BETWEEN WALLS\n");
				}
			}
			j++;
		}
		i++;
	}
}

void	open_door(t_data *data)
{
	if (data->map[(int)(data->player_y / 50) - 1][(int)(data->player_x / 50)] == 'D'
		&& data->player_a > 180 && data->player_a < 360)
	{
		data->map[(int)(data->player_y / 50) - 1][(int)(data->player_x / 50)] = '0';
	}
	else if (data->map[(int)(data->player_y / 50) + 1][(int)(data->player_x / 50)] == 'D'
		&& data->player_a > 0 && data->player_a < 180)
	{
		data->map[(int)(data->player_y / 50) + 1][(int)(data->player_x / 50)] = '0';
	}
	else if (data->map[(int)(data->player_y / 50)][(int)(data->player_x / 50) - 1] == 'D'
		&& (data->player_a > 90 && data->player_a < 270))
	{
		data->map[(int)(data->player_y / 50)][(int)(data->player_x / 50) - 1] = '0';
	}
	else if (data->map[(int)(data->player_y / 50)][(int)(data->player_x / 50) + 1] == 'D'
		&& (data->player_a > 270 || data->player_a < 90))
	{
		data->map[(int)(data->player_y / 50)][(int)(data->player_x / 50) + 1] = '0';
	}
	move_stright_b(data);
    rendering_3dbonus_map(data);
}