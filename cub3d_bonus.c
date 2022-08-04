/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:49:22 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/04 13:39:26 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int ac, char **argv)
{
    if(ac != 2)
        return (0);
    t_data data;
    parsing(argv, &data);
    rendering_bonus(&data);
}