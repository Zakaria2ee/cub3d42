/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:49:22 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/11 13:56:48 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

int main(int ac, char **argv)
{
    if(ac != 2)
        return (0);
    t_data data;
    parsing_b(argv, &data);
    rendering_bonus(&data);
}