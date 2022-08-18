/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:49:22 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/17 16:43:10 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	main(int ac, char **argv)
{
	t_data	data;

	if (ac != 2)
		return (0);
	parsing_b(argv, &data);
	rendering_bonus(&data);
}
