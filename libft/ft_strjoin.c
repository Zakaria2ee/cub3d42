/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:36:33 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/21 15:31:57 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		size;
	int		i;
	int		j;
	char	*arr;

	i = 0;
	j = 0;
	if (!s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	arr = malloc((size + 1) * sizeof(char));
	if (arr == 0)
		return (0);
	if (s1)
	{
		while (s1[j] && i < size)
			arr[i++] = s1[j++];
	}
	j = 0;
	while (s2[j] && i < size)
		arr[i++] = s2[j++];
	arr[i] = '\0';
	if (s1)
		free(s1);
	return (arr);
}
