/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:45:09 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/04 12:33:00 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void error_handler(t_data *data)
{
   new_line_errors(data->saved);
   data->map = ft_split(data->saved, '\n');
   empty_errors(data);
}

void new_line_errors(char *str)
{
    int i;

    i = 0;
    while(str[i] != '1')
        i++;
    while(str[i])
    {
        if(str[i] == '\n' && str[i + 1] == '\n')
            ft_exit("Error\n");
        i++;
    }
}

void empty_errors(t_data *data)
{
    int i;
    int j;
    int counter;

    i = 0;
    counter = 0;
    data->column = 0;
    data->line = 0;
    while(data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if(data->map[i][j] == '0')
                check_space(i,j,data->map);
            if(data->map[i][j] != '1' && data->map[i][j] != '0' && delimiters(data->map[i][j]))
                 counter++;
            if(delimiters(data->map[i][j]) && data->map[i][j] != '1' &&  data->map[i][j] != '0')
            {
                data->player_y =  (i * 50) + 25;
                data->player_x = (j * 50) + 25;
            }
            j++;
        }
        if(j > data->line)
            data->line = j;
        i++;
    }
    data->column = i;
    if(counter > 1)
        ft_exit("ERROR\nMore than one player\n");
}

void check_space(int i, int j, char **map)
{
    if(map[i][j] && !delimiters(map[i][j + 1]))
        ft_exit("ERROR\n");
    else if(j && !delimiters(map[i][j - 1]))
        ft_exit("ERROR\n");
    else if((i && (ft_strlen(map[i - 1]) >= (size_t)j) && !delimiters(map[i - 1][j])) || ((ft_strlen(map[i - 1]) < (size_t)j)))
        ft_exit("ERROR\n");
    else if((map[i] && (ft_strlen(map[i + 1]) >= (size_t)j) && !delimiters(map[i + 1][j])) || ((ft_strlen(map[i - 1]) < (size_t)j)))
        ft_exit("ERROR\n");
}

int delimiters(char c)
{
    if(c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '0')
        return (1);
    else
        return (0);
}

void get_player_a(t_data *data)
{
    int i;
    int j;

    i = 0;
    while(data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if(data->map[i][j] == 'N')
            {
                data->map[i][j] = '0';
                data->player_a = 270;
            }
            else if(data->map[i][j] == 'S')
            {
                data->player_a = 90;
                data->map[i][j] = '0';
            }
            else if(data->map[i][j] == 'E')
            {
                data->player_a = 0;
                data->map[i][j] = '0';
            }
            else if(data->map[i][j] == 'W')
            {
                data->player_a = 180;
                data->map[i][j] = '0';
            }
            j++;
        }
        i++;
    }
}