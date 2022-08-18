/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:01:23 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/18 12:09:10 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char *get_texture(char *s);
void invalid_textures(char *filename);
void get_textures(char **argv, t_data *data)
{
    int count;

    data->fd = open(argv[1], O_RDONLY);
    if(data->fd < 0)
        ft_exit("Error\nfile not found\n");
    count = 0;
    while(count < 6)
    {
        char *s = get_next_line(data->fd);
        if(*s != '\n')
        {
            check_path((s += skip_space(s)), data);
            count++;
        }
    }
}

void check_path(char *s, t_data *data)
{
    if (!ft_memcmp(s, "NO ", 3))
	{
		if(!data->north)
		{
			data->north = get_texture(s + 3);
			invalid_textures(data->north);
		}
		else
			ft_exit("Error\nDouble textures\n");
	}
	else if (!ft_memcmp(s, "SO ", 3))
	{
		if(!data->south)
		{
			data->south = get_texture(s + 3);
			invalid_textures(data->south);
		}
		else
			ft_exit("Error\nDouble textures\n");
	}
	else if (!ft_memcmp(s, "EA ", 3))
	{
		if(!data->east)
		{
			data->east = get_texture(s + 3);
			invalid_textures(data->east);
		}
		else
			ft_exit("Error\nDouble textures\n");
	}
	else if (!ft_memcmp(s, "WE ", 3))
	{
		if(!data->west)
		{
			data->west = get_texture(s + 3);
			invalid_textures(data->west);
		}
		else
			ft_exit("Error\nDouble textures\n");
	}
	else if (!ft_memcmp(s, "F ", 2))
		data->floor = hexa_colors(ft_strdup((s + (skip_space(s) + 2))));
	else if (!ft_memcmp(s, "C ", 2))
		data->sky = hexa_colors(ft_strdup((s + (skip_space(s) + 2))));
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

char *get_texture(char *s)
{
	int i;
	int j;
	char *tex;

	j = skip_space(s);
	i = 0;
	while(s[j] != '\n')
		j++;
	tex = malloc(sizeof(char) * (j - skip_space(s)) + 1);
	if(!tex)
		return (0);
	j = skip_space(s);
	while(s[j] != '\n')
	{
		tex[i] = s[j];
		i++;
		j++;
	}
	tex[i] = '\0';
	return (tex);
}

void invalid_textures(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if(fd < 0)
	{
		ft_putstr_fd("ERROR\nInvalid texture\n", 2);	
		exit(0);
	}
	else
		close(0);
}