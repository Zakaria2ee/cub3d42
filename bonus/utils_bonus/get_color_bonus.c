/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:21:20 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/20 15:25:36 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	get_color_b(t_data *data, int *dirray, int y, int d)
{
	int	pixel;

	if (d > 180)
		d = 180;
	if (dirray[2] == 'D')
		pixel = (*(int *)(data->door.addr + (y * data->door.line_len
						+ dirray[1] * (data->door.bpp / 8))));
	else if (dirray[0] == 's')
		pixel = (*(int *)(data->s.addr + (y * data->s.line_len
						+ dirray[1] * (data->s.bpp / 8))));
	else if (dirray[0] == 'w')
		pixel = (*(int *)(data->we.addr + (y * data->we.line_len
						+ dirray[1] * (data->we.bpp / 8))));
	else if (dirray[0] == 'n')
		pixel = (*(int *)(data->n.addr + (y * data->n.line_len
						+ dirray[1] * (data->n.bpp / 8))));
	else
		pixel = (*(int *)(data->e.addr + (y * data->e.line_len
						+ dirray[1] * (data->e.bpp / 8))));
	return (pixel + ((unsigned char)d << 24));
}