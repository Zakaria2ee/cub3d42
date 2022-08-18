/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:34:44 by mabenchi          #+#    #+#             */
/*   Updated: 2022/08/18 12:49:35 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void init2(t_data *data);
int res_len(int *str);

int	parsing_b(char **argv, t_data *data)
{
	init2(data);
	check_extention(argv[1]);
	get_textures(argv, data);
	get_map(argv, data);
	error_handler(data);
	check_doors(data);
	get_player_a(data);
	return (0);
}

int	hexa_colors(char *str)
{
	char	*s;
	int		i;
	int		j;
	int		start;
	int		res[8];

	i = 0;
	start = 0;
	j = 0;
	while (str[i])
	{
		while (ft_isnum(str[i]))
			i++;
		s = ft_substr(str, start, (i - start));
		start = i + 1;
		res[j] = ft_atoi(s); 
		if(!res[j])
			ft_exit("Error\nWrong color\n");
		j++;
		i++;
	}
	if(res_len(res) > 3)
		ft_exit("Error\nWrong Color\n");
	return ((res[0] << 16) + (res[1] << 8) + res[2]);
}

int res_len(int *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void init2(t_data *data)
{
	data->east = 0;
	data->west = 0;
	data->south = 0;
	data->north = 0;
}
