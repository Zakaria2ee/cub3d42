/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:49:22 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/14 16:11:49 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

int	main(int ac, char **argv)
{
	t_data	data;

	if (ac != 2)
		return (0);
	parsing_b(argv, &data);
	rendering_bonus(&data);
}
