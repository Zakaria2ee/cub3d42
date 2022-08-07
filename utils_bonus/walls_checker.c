/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:06:20 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/07 21:42:28 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int walls_checker2_b(int x, int y, float dy, float dx, t_data *data)
{
    if(data->map[(int)(y - dy)/50][(int)(x - dx)/50] == '1' || data->map[(int)(y - dy)/50][(int)(x - dx)/50] == 'D')
         return (0);
    if(data->map[(int)(y - dy) / 50][(int)(x / 50)] == '1' 
    || data->map[(int)(y - dy) / 50][(int)(x / 50)] == 'D')
        return  (0);
    return (1);
}

int walls_checker3_b(double x, double y, float dy, float dx, t_data *data)
{
    if (data->map[(int)(y + dy) / 50][(int)(x / 50)] == 'D' || data->map[(int)(y / 50)][(int)(x + dx) / 50] == 'D')
        data->is_door = 'D';
    if (data->map[(int)(y + dy) / 50][(int)(x / 50)] == '1' || data->map[(int)(y + dy) / 50][(int)(x / 50)] == 'D')
        return ('y');
    if (data->map[(int)(y / 50)][(int)(x + dx) / 50] == '1' || data->map[(int)(y / 50)][(int)(x + dx) / 50] == 'D')
        return ('x');
    if(data->map[(int)(y + dy) / 50][(int)(x + dx) / 50] == '1' || data->map[(int)(y + dy) / 50][(int)(x / 50)] == 'D')
        return (1);
    return (0);
}