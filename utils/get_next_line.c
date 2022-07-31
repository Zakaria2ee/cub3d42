/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:08:53 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/21 09:26:43 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char *get_next_line(int fd)
{
    char *s;
    char *tmp;


    s = malloc(1000);

    tmp = s;
    while(read(fd, tmp, 1) > 0 && *tmp++ != '\n');
    if(tmp > s)
    {
        *tmp = 0;
        return s;
    }
    else
    {
        free(s);
        return (NULL);
    }
}