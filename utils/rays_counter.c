/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:44:12 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/30 19:53:54 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void rays_counter(t_data *data, double *rays)
{
    int i;
    double ray;
    double r;
    double angle;

    i = -1;
    angle = data->player_a - 30;
    r = -30;
    while(++i < 1200)
    { 
        ray = 0;
        if(angle >= 360)
            angle -= 360;
        else if(angle < 0)
            angle += 360;
        get_ray(data, angle, &ray, r);
        rays[i] = ray;
        angle += 0.05;
        r += 0.05;
    }
}

void get_ray(t_data *data, double angle, double *ray, int r)
{
    double x;
    double y;

    x = data->player_x;
    y = data->player_y;
    while(walls_checker3(x, y, 1 * sin(angle * PI/180),  1 * cos(angle * PI/180), data))
    {
        x += 1 * cos(angle * PI/180);
        y += 1 * sin(angle * PI/180);
    }
    x -= 1 * cos(angle * PI/180);
    y -= 1 * sin(angle * PI/180);
    while(walls_checker3(x, y, 0.01 * sin(angle * PI/180),  0.01 * cos(angle * PI/180), data))
    {
        x += 0.1 * cos(angle * PI/180);
        y += 0.1 * sin(angle * PI/180); 
    }
    *ray = (sqrt(((data->player_x - x) *  (data->player_x - x)) + ((data->player_y - y) * (data->player_y - y)))) * cos(r * PI/180);
    if(*ray < 1)
        *ray = 1;
}