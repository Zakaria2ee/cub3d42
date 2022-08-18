/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:29:41 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/18 14:30:53 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int res_len(int *str);
int	hexa_colors(char *str)
{
	char	*s;
	int		i;
	int		j;
	int		start;
	int		res[8];

	i = 0;
	start = 0;
	j = 0;
	while (str[i])
	{
		while (ft_isnum(str[i]))
			i++;
		s = ft_substr(str, start, (i - start));
		start = i + 1;
		res[j] = ft_atoi(s); 
		if(!res[j])
			ft_exit("Error\nWrong color\n");
		j++;
		i++;
	}
	if(res_len(res) > 3)
		ft_exit("Error\nWrong Color\n");
	return ((res[0] << 16) + (res[1] << 8) + res[2]);
}

int res_len(int *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}