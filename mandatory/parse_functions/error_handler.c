/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:45:09 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/21 13:57:58 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	error_handler(t_data *data)
{
	new_line_errors(data->saved);
	data->map = ft_split(data->saved, '\n');
	empty_errors(data);
	check_invalid_textures(data->north);
	check_invalid_textures(data->south);
	check_invalid_textures(data->east);
	check_invalid_textures(data->west);
}

void	new_line_errors(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '1')
		i++;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			ft_exit("Error\n");
		i++;
	}
}

void	empty_errors(t_data *data)
{
	int	j;
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (data->map[i])
	{
		j = 0;
		check_error(i, data, &counter, &j);
		if (j > data->line)
			data->line = j;
		i++;
	}
	data->column = i;
	if (counter > 1)
		ft_exit("ERROR\nMore than one player\n");
}

void	check_space(int i, int j, char **map)
{
	if (map[i][j] && !delimiters(map[i][j + 1]))
		ft_exit("ERROR\n");
	else if (j && !delimiters(map[i][j - 1]))
		ft_exit("ERROR\n");
	else if ((i && (ft_strlen(map[i - 1]) >= (size_t)j)
			&& !delimiters(map[i - 1][j]))
			|| ((ft_strlen(map[i - 1]) < (size_t)j)))
		ft_exit("ERROR\n");
	else if ((map[i] && (ft_strlen(map[i + 1]) >= (size_t)j)
			&& !delimiters(map[i + 1][j]))
			|| ((ft_strlen(map[i - 1]) < (size_t)j)))
		ft_exit("ERROR\n");
}

void	check_error(int i, t_data *data, int *counter, int *j)
{
	while (data->map[i][*j])
	{
		if (data->map[i][*j] == '0')
			check_space(i, *j, data->map);
		if (data->map[i][*j] != '1'
			&& data->map[i][*j] != '0' && delimiters(data->map[i][*j]))
			(*counter)++;
		if (delimiters(data->map[i][*j]) && data->map[i][*j] != '1'
			&& data->map[i][*j] != '0')
		{
			data->player_y = (i * 50) + 25;
			data->player_x = (*j * 50) + 25;
		}
		if (!delimiters(data->map[i][*j]) && data->map[i][*j] != ' ')
			ft_exit("Error\n");
		if (data->map[i][*j] == 'N'
			|| data->map[i][*j] == 'S' || data->map[i][*j] == 'E'
			|| data->map[i][*j] == 'W')
			check_space(i, *j, data->map);
		(*j)++;
	}
}
