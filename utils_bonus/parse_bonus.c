/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:34:44 by mabenchi          #+#    #+#             */
/*   Updated: 2022/08/11 13:35:20 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int parsing_b(char **argv, t_data *data)
{
    check_extention(argv[1]);
    get_textures(argv, data);
    get_map(argv, data);
    error_handler(data);
    check_doors(data);
    get_player_a(data);
    return (0);
}

int hexa_colors(char *str)
{
    char *s;
    int i;
    int j;
    int start;
    int res[3];

    i =0;
    start = 0;
    j = 0;
    while(str[i])
    {
        while(ft_isnum(str[i]))
            i++;
        s = ft_substr(str, start, (i - start));
       
        start = i + 1;
        res[j] = ft_atoi(s); 
        
        j++;
        i++;
    }
    return ((res[0] << 16) + (res[1] << 8) + res[2]);
}