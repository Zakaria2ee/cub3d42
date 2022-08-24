/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:01:23 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/24 11:37:44 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		if (!s)
			break ;
		if (*s != '\n')
		{
			check_path((s += skip_space(s)), data);
			count++;
		}
		free(s);
	}
	if (count < 6)
		ft_exit("Error\nincompleted elements\n");
}

void	check_path(char *s, t_data *data)
{
	if (!ft_memcmp(s, "NO ", 3) && !data->north)
			data->north = get_texture(s + 3);
	else if (!ft_memcmp(s, "SO ", 3) && !data->south)
			data->south = get_texture(s + 3);
	else if (!ft_memcmp(s, "EA ", 3) && !data->east)
			data->east = get_texture(s + 3);
	else if (!ft_memcmp(s, "WE ", 3) && !data->west)
			data->west = get_texture(s + 3);
	else if (!ft_memcmp(s, "F ", 2))
		data->floor = hexa_colors(ft_strdup((s + (skip_space(s) + 2))));
	else if (!ft_memcmp(s, "C ", 2))
		data->sky = hexa_colors(ft_strdup((s + (skip_space(s) + 2))));
	else
		ft_exit("Error\nWrong texture\n");
}

char	*get_texture(char *s)
{
	int		i;
	int		j;
	char	*tex;

	j = skip_space(s);
	i = 0;
	while (s[j] != '\n')
		j++;
	tex = malloc(sizeof(char) * (j - skip_space(s)) + 1);
	if (!tex)
		return (0);
	j = skip_space(s);
	while (s[j] != '\n')
	{
		tex[i] = s[j];
		i++;
		j++;
	}
	tex[i] = '\0';
	return (tex);
}
