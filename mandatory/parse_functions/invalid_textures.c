/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:26:57 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/19 16:27:13 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void check_invalid_textures(char *filename)
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