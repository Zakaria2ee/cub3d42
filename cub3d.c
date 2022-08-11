/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:38:50 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/11 11:58:13 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int ac, char **argv)
{
    if(ac != 2)
        return (0);
    t_data data;
    parsing(argv, &data);
    rendering(&data);
}