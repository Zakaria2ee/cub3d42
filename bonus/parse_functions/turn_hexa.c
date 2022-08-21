/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:29:41 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/21 12:18:36 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	hexa_colors(char *str)
{
	char	*s;
	int		i;
	int		j;
	int		start;
	int		res[8];

	i = -1;
	start = 0;
	j = 0;
	while (str[++i])
	{
		while (ft_isnum(str[i]))
			i++;
		s = ft_substr(str, start, (i - start));
		start = i + 1;
		res[j] = ft_atoi(s);
		if (!res[j++])
			ft_exit("Error\nWrong color\n");
		free(s);
	}
	res_len(res);
	free(str);
	return ((res[0] << 16) + (res[1] << 8) + res[2]);
}

int	res_len(int *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 3)
		ft_exit("Error\nWrong Color\n");
	return (i);
}
