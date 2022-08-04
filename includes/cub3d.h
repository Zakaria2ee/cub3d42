/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:39:03 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/04 20:34:53 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CUB3D_H
#define CUB3D_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
#define PX 10
#define RA 10
#define RSX 1200
#define RSY 800
#define TEXY 200
#define TEXX 200
#define MINIX 200
#define MINIY 200

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
    int     w;
    int     h;
}	t_img;

typedef struct  data_t
{
    char **map;
    char *saved;
    char *South;
    char *North;
    char *West;
    char *East;
    t_img s;
    t_img n;
    t_img e;
    t_img we;
    int Floor;
    int Sky;
    int fd;
    char *mlx_win;
    char *mlx;
    int line;
    int column;
    t_img img1;
    t_img img2;
    void *player;
    int player_x;
    int player_y;
    int player_a;
    int player_dx;
    int player_dy;
    int h;
    int w;
    int ray_x;
    int ray_y;
    int color;
    t_img img;
    t_img black;
    t_img mini_wall;
    int dirRay[RSX][2];
} t_data;






void init(t_data *data);
//char	wall_checker2(t_data	*data);
//char	wall_checker(t_data	*data);
//char	check_map(t_data	*data);
//int	set_up_map(char	*path, t_data	*data);
//void	set_line(char	*str, t_data	*data);
//void	set_column(char	*str, t_data	*data);
//int	set_map(char	*path, t_data	*data);
void	check_extention(char *path);



void	ft_exit(char *str);
void    get_textures(char **argv, t_data *data);
void    get_map(char **argv, t_data *data);
int     parsing(char **argv, t_data *data);
char    *get_next_line(int fd);
void    check_path(char *s, t_data *data);
void    error_handler(t_data *data);
void    new_line_errors(char *str);
int     ft_close();
int     skip_space(char *s);
int     delimiters(char c);
void    rendering(t_data *data);
int     key_hook(int keycode, t_data *data);
void    init(t_data *data);
void    empty_errors(t_data *data);
void    check_space(int i, int j, char **map);
void    rays_counter(t_data *data, double *rays);
double get_ray(t_data *data, double angle, int i, int r);
int     ft_isnum(char c);



int     walls_checker(int x, int y, t_data *data);
int     walls_checker2(int x, int y, float dy, float dx, t_data *data);
int     walls_checker3(double x, double y, float dy, float dx, t_data *data);

void    get_player_a(t_data *data);
void    ft_put_pxl(t_img *img, int x, int y, int color);
void    render_2dmap(t_data *data);
int     key_hook(int keycode, t_data *data);
void    rays_to_image(t_data *data, double *rays);
void    rendering_3d_map(t_data *data);
void    put_pixles(t_img img, int current_x, double *rays,  t_data *data);
void	put_black_background(t_data *data);
void    put_black_pixel(t_data *data);

void    move_back(t_data *data);
void    move_stright(t_data *data);
void    move_right(t_data *data);
void    move_left(t_data *data);

void    look_right(t_data *data);
void    look_left(t_data *data);

int     ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strdup(char *str);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char	*str);
int     ft_strcmp(char	*s1, char	*s2);
char	*ft_substr(char	const *s, unsigned	int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char	const *s, char c);
int	    ft_atoi(const char	*str);


int hexa_colors(char *str);

//-----------bonus-------//
void    rendering_3dbonus_map(t_data *data);
int     bonus_key_hook(int keycode, t_data *data);
void    rendering_bonus(t_data *data);



#endif