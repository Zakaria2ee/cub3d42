/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extention.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:46:56 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/14 14:43:25 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	check_extention(char *path)
{
	int	len_path;

	len_path = ft_strlen(path);
	if (len_path < 4)
		ft_exit("Error\nwrong Extention\n");
	if (path[len_path - 5] == '.' || path[len_path - 5] == '/')
		ft_exit("Error\nwrong Extention\n");
	if (ft_strcmp(path + len_path - 4, ".cub"))
		ft_exit("Error\nwrong Extention\n");
}

int	delimiters(char c)
{
	if (c == '1' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == '0' || c == 'D')
		return (1);
	else
		return (0);
}