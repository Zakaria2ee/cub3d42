/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:38:50 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/19 15:40:00 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **argv)
{
	t_data	data;

	if (ac != 2)
		return (0);
	parsing(argv, &data);
	rendering(&data);
	system("leaks cub3d");
}
