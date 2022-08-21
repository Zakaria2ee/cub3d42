/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:39:03 by zboudair          #+#    #+#             */
/*   Updated: 2022/08/21 15:31:13 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CUB3D_H
# define CUB3D_H

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
	t_img	img;
	t_img	black;
	t_img	door;
	int		dirray[RSX][3];
	int		keys[8];
	int		current_y;
	int		tcolor;
}	t_data;
//------------parse----------------//
void	init(t_data *data);
void	ft_exit(char *str);
void	get_textures(char **argv, t_data *data);
void	get_map(char **argv, t_data *data);
int		parsing(char **argv, t_data *data);
char	*get_next_line(int fd);
void	init1(t_data *data);
char	*get_texture(char *s);
void	check_invalid_textures(char *filename);
void	check_p(t_data *data, int i, int j, int *counter);
void	check_p2(t_data *data, int i, int j, int *counter);
void	check_error(int i, t_data *data, int *counter, int *j);
int		res_len(int *str);
//----------------------------------//
//-----------utils---------------//
int		ft_close(void);
int		skip_space(char *s);
int		delimiters(char c);
void	rendering(t_data *data);
int		key_hook(int keycode, t_data *data);
void	init(t_data *data);
void	rays_counter(t_data *data, double *rays);
void	get_player_a(t_data *data);
void	ft_put_pxl(t_img *img, int x, int y, int color);
int		key_hook(int keycode, t_data *data);
void	rays_to_image(t_data *data, double *rays);
void	rendering_3d_map(t_data *data);
void	put_black_background(t_data *data);
void	put_black_pixel(t_data *data);
int		hexa_colors(char *str);
void	ft_put_pxl(t_img *img, int x, int y, int color);
void	put_pixles(t_img img, int current_x, double *rays, t_data *data);
void	render_sky(t_data *data, t_img img, int current_x);
void	ini(int *i, double *rays, int current_x);

//--------------------------------------------------//
//----------------errors_check---------------//
void	check_path(char *s, t_data *data);
void	error_handler(t_data *data);
void	check_extention(char *path);
void	new_line_errors(char *str);
void	check_space(int i, int j, char **map);
void	empty_errors(t_data *data);
int		walls_checker(int x, int y, t_data *data);
int		walls_checker2(int x, int y, float dy, float dx, t_data *data);
int		walls_checker3(double x, double y, float dy, float dx, t_data *data);
//-----------------------------------------------//

//--------moves-----------//
void	move_back(t_data *data);
void	move_stright(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	look_right(t_data *data);
void	look_left(t_data *data);
//-------------------------//

//----------libft---------//
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
//-------------------------//
#endif
