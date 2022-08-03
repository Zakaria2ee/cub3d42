/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:44:12 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/03 09:54:23 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void rays_counter(t_data *data, double *rays, int *dirRay)
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
        dirRay[i] = get_ray(data, angle, &ray, r);
        rays[i] = ray;
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

int get_ray(t_data *data, double angle, double *ray, int r)
{
    double x;
    double y;
    int dirRay;

    x = data->player_x;
    y = data->player_y;
    while(!walls_checker3(x, y, 1 * sin(angle * PI/180),  1 * cos(angle * PI/180), data))
    {
        x += 1 * cos(angle * PI/180);
        y += 1 * sin(angle * PI/180);
    }
    x -= 1 * cos(angle * PI/180);
    y -= 1 * sin(angle * PI/180);
    dirRay = walls_checker3(x, y, 0.1 * sin(angle * PI/180),  0.1 * cos(angle * PI/180), data);
    while(!dirRay)
    {
        x += 0.1 * cos(angle * PI/180);
        y += 0.1 * sin(angle * PI/180); 
        dirRay = walls_checker3(x, y, 0.1 * sin(angle * PI/180),  0.1 * cos(angle * PI/180), data);
    }
    *ray = (sqrt(((data->player_x - x) *  (data->player_x - x)) + ((data->player_y - y) * (data->player_y - y)))) * cos(r * PI/180);
    if(*ray < 1)
        *ray = 1;
    dirRay = direction(dirRay, x, y, data);
    return (dirRay);
}