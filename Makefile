# _*_ MakeFile _*_

NAME = cub3d
BONUSNAME= cub3d_bonus

CC = cc



FLGS = -Wextra -Wall -Werror -O3

FUNCTION = utils/ft_exit.c utils/ft_check_extention.c utils/get_next_line.c \
		utils/get_textures.c utils/get_map.c utils/error_handler.c utils/ft_close.c \
		utils/look_left.c utils/look_right.c utils/walls_checker.c  \
		utils/move_left.c utils/move_right.c  utils/put_black_img.c \
		utils/parse.c utils/ft_put_pxl.c \

UTLS = utils/render.c  utils/rendering_3D_map.c utils/key_hook.c  utils/move_stright.c utils/move_back.c\
		utils/rays_to_image.c utils/rays_counter.c

		

UTLS_BONUS = utils_bonus/ft_exit.c utils_bonus/ft_check_extention.c utils_bonus/get_next_line.c \
			utils_bonus/get_textures.c utils_bonus/get_map.c utils_bonus/error_handler.c utils_bonus/ft_close.c \
			utils_bonus/look_left.c utils_bonus/look_right.c\
			utils_bonus/move_left.c utils_bonus/move_right.c  utils_bonus/put_black_img.c utils_bonus/ft_put_pxl.c \
			utils_bonus/rendering_3dbonus_map.c utils_bonus/render_bonus.c utils_bonus/bonus_key_hook.c utils_bonus/minimap.c \
			utils_bonus/rays_to_image_b.c utils_bonus/walls_checker.c utils_bonus/rays_counter_b.c utils_bonus/door.c \
			utils_bonus/move_stright_back.c utils_bonus/key_press.c utils_bonus/key_release.c utils_bonus/parse_bonus.c
 
LIBFT = libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strcmp.c \
		libft/ft_split.c libft/ft_memcmp.c libft/ft_putstr_fd.c \
		libft/ft_strdup.c libft/ft_substr.c libft/ft_atoi.c utils/ft_isnum.c \



SRCS = 

all: $(NAME)

$(NAME):   $(UTLS) $(FUNCTION) $(LIBFT)
	@$(CC) $(FLGS) -I /usr/local/include cub3d.c -L /usr/local/lib -pthread -lmlx -framework OpenGL -framework AppKit $(UTLS) $(FUNCTION) $(LIBFT) -fsanitize=address -o $(NAME)

bonus :
	@$(CC) $(FLGS) -I /usr/local/include cub3d_bonus.c -L /usr/local/lib -pthread -lmlx -framework OpenGL -framework AppKit $(UTLS_BONUS) $(LIBFT) -fsanitize=address -o $(BONUSNAME)
clean : 
	@rm -rf $(NAME) $(BONUSNAME)
	
fclean : clean

re : fclean all

.PHONY: re all fclean clean