/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:44:12 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/04 12:34:08 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void rays_counter(t_data *data, double *rays)
{
    int i;
    double r;
    double angle;

    i = -1;
    angle = data->player_a - 30;
    r = -30;
    while(++i < 1200)
    { 
        if(angle >= 360)
            angle -= 360;
        else if(angle < 0)
            angle += 360;
        rays[i] = get_ray(data, angle, i, r);
        angle += 0.05;
        r += 0.05;
    }
}

int direction(int dirRay, int x, int y, t_data *data)
{
    if (dirRay == 'x' && (data->player_x > x))
        dirRay = 's';
    else if (dirRay == 'x')
        dirRay = 'n';
    else if (dirRay == 'y' && (data->player_y > y))
        dirRay = 'e';
    else
        dirRay = 'w';
    return (dirRay);
}

double get_ray(t_data *data, double angle, int i, int r)
{
    double x;
    double y;
    double ray;
    int d_Ray;

    x = data->player_x;
    y = data->player_y;
    while(!walls_checker3(x, y, 1 * sin(angle * PI/180),  1 * cos(angle * PI/180), data))
    {
        x += 1 * cos(angle * PI/180);
        y += 1 * sin(angle * PI/180);
    }
    x -= 1 * cos(angle * PI/180);
    y -= 1 * sin(angle * PI/180);
    d_Ray = walls_checker3(x, y, 0.1 * sin(angle * PI/180),  0.1 * cos(angle * PI/180), data);
    while(!d_Ray)
    {
        x += 0.1 * cos(angle * PI/180);
        y += 0.1 * sin(angle * PI/180); 
        d_Ray = walls_checker3(x, y, 0.1 * sin(angle * PI/180),  0.1 * cos(angle * PI/180), data);
    }
    ray = (sqrt(((data->player_x - x) *  (data->player_x - x)) + ((data->player_y - y) * (data->player_y - y)))) * cos(r * PI/180);
    if (ray < 1)
        ray = 1;
    data->dirRay[i][0] = direction(d_Ray, x, y, data);
    if (data->dirRay[i][0] == 's' || data->dirRay[i][0] == 'n')
        data->dirRay[i][1] = (int)(y * 4) % TEXY;
    else
        data->dirRay[i][1] = (int)(x * 4) % TEXX;
    return (ray);
}