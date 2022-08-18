/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:01:41 by mabenchi          #+#    #+#             */
/*   Updated: 2022/08/16 15:02:45 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# define PI 3.14159265358979323846
# define PX 10
# define RA 10
# define RSX 1200
# define RSY 800
# define TEXY 200
# define TEXX 200
# define MINIX 200
# define MINIY 200

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_point
{
	int	x;
	int	y;
}	t_cord;

typedef struct data_t
{
	int		is_door;
	char	**map;
	char	*saved;
	char	*south;
	char	*north;
	char	*west;
	char	*east;
	t_img	s;
	t_img	n;
	t_img	e;
	t_img	we;
	int		floor;
	int		sky;
	int		fd;
	char	*mlx_win;
	char	*mlx;
	int		line;
	int		column;
	t_img	minimap;
	t_img	img2;
	void	*player;
	int		player_x;
	int		player_y;
	int		player_a;
	int		player_dx;
	int		player_dy;
	int		h;
	int		w;
	int		ray_x;
	int		ray_y;
	int		color;
	t_img	screen;
	t_img	black;
	t_img	door;
	t_img	door_a[7];
	int		opened_door;
	int		dirray[RSX][3];
	int		keys[8];
}	t_data;

//-------parse--------------//
void	init(t_data *data);
void	ft_exit(char *str);
void	get_textures(char **argv, t_data *data);
void	get_map(char **argv, t_data *data);
char	*get_next_line(int fd);
void	get_player_a(t_data *data);
int		parsing_b(char **argv, t_data *data);
int		ft_close(void);
int		skip_space(char *s);
int		delimiters(char c);

//-------errors---------------------------//
void	check_path(char *s, t_data *data);
void	error_handler(t_data *data);
void	new_line_errors(char *str);
int		walls_checker(int x, int y, t_data *data);
void	check_extention(char *path);
void	empty_errors(t_data *data);
void	check_space(int i, int j, char **map);
void	check_doors(t_data *data);
int		walls_checker3_b(double x, double y, float dy, float dx, t_data *data);

//-----------moves-----------------//
void	move_right(t_data *data);
void	move_left(t_data *data);
void	look_right(t_data *data);
void	look_left(t_data *data);
void	move_stright_b(t_data *data);
void	move_back_b(t_data *data);

//----------------libft---------------------------//
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strdup(char *str);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char	*str);
int		ft_strcmp(char	*s1, char	*s2);
char	*ft_substr(char	const *s, unsigned	int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char	const *s, char c);
int		ft_atoi(const char	*str);
int		ft_isnum(char c);

//----------------bonus_functions--------------------//
void	rendering_3dbonus_map(t_data *data);
int		bonus_key_hook(int keycode, t_data *data);
void	rendering_bonus(t_data *data);
void	mini_map(t_data *data);
void	rays_counter_b(t_data *data, double *rays);
void	rays_to_image_b(t_data *data, double *rays);
void	open_door(t_data *data);
int		walls_checker2_b(int x, int y, float dy, float dx, t_data *data);
int		add_key_release(int keycode, t_data *data);
int		add_key_press(int keycode, t_data *data);
int		render_map(t_data *data);
void	close_door(t_data *data);
double	distance(int x, int y, int x1, int y1);
void	ft_put_pxl(t_img *img, int x, int y, int color);
void	put_black_background(t_data *data);
void	put_black_pixel(t_data *data);
int		hexa_colors(char *str);
void	ft_put_pxl(t_img *img, int x, int y, int color);
void	put_pixles(t_img img, int current_x, double *rays,  t_data *data);
//--------------------------------------------------------//
#endif