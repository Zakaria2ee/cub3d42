/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:01:23 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/12 17:17:06 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_textures(char **argv, t_data *data)
{
	int		count;
	char	*s;

	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
		ft_exit("Error\nfile not found\n");
	count = 0;
	while (count < 6)
	{
		s = get_next_line(data->fd);
		if (*s != '\n')
		{
			check_path((s += skip_space(s)), data);
			count++;
		}
	}
}

void	check_path(char *s, t_data *data)
{
	if (!ft_memcmp(s, "NO ", 3))
	{
		s += 3;
		data->North = ft_strdup((s += skip_space(s)));
	}
	else if (!ft_memcmp(s, "SO ", 3))
	{
		s += 3;
		data->South = ft_strdup((s += skip_space(s)));
	}
	else if (!ft_memcmp(s, "EA ", 3))
	{
		s += 3;
		data->East = ft_strdup((s += skip_space(s)));
	}
	else if (!ft_memcmp(s, "WE ", 3))
	{
		s += 3;
		data->West= ft_strdup((s += skip_space(s)));
	}
	else if (!ft_memcmp(s, "F ", 2))
	{
		s += 2;
		data->Floor = hexa_colors(ft_strdup((s += skip_space(s))));
	}
	else if (!ft_memcmp(s, "C ", 2))
	{
		s += 2;
		data->Sky =  hexa_colors(ft_strdup((s += skip_space(s))));
	}
	else
		ft_exit("Error\nWrong texture\n");
}

int skip_space(char *s)
{
    int i;

    i = 0;
    while(s[i] == ' ')
        i++;
    return (i);
}