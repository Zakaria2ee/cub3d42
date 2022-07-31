/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extention.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:46:56 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/21 12:21:15 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_extention(char *path)
{
	int	len_path;

	len_path = ft_strlen(path);
	if (len_path < 4)
		ft_exit("Error\nwrong Extention\n");
	if(path[len_path - 5] == '.' || path[len_path - 5] == '/')
		ft_exit("Error\nwrong Extention\n");
	if (ft_strcmp(path + len_path - 4, ".cub"))
		ft_exit("Error\nwrong Extention\n");
}