/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:38:50 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/14 16:12:23 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int ac, char **argv)
{
	t_data	data;

	if (ac != 2)
		return (0);
	parsing(argv, &data);
	rendering(&data);
}
