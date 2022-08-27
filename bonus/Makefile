# _*_ MakeFile _*_

NAME = cub3d_bonus

CC = cc

FLGS = -Wextra -Wall -Werror -O3

MLX =  -I /usr/local/include  -L /usr/local/lib -pthread -lmlx -framework OpenGL -framework AppKit

UTLS_BONUS =  utils_bonus/put_black_img_bonus.c utils_bonus/ft_put_pxl_bonus.c \
			utils_bonus/rendering_3dbonus_map.c utils_bonus/render_bonus.c \
			utils_bonus/key_hook_bonus.c utils_bonus/minimap_bonus.c utils_bonus/rays_to_image_bonus.c utils_bonus/walls_checker_bonus.c \
			utils_bonus/rays_counter_bonus.c utils_bonus/door_bonus.c utils_bonus/key_press_bonus.c utils_bonus/key_release_bonus.c  \
			utils_bonus/get_color_bonus.c

MOVES = moves/look_left_bonus.c moves/look_right_bonus.c moves/move_left_bonus.c moves/move_right_bonus.c moves/move_stright_back_bonus.c\
		 

PARSE_FUNC = parse_functions/ft_exit_bonus.c parse_functions/ft_check_extention_bonus.c parse_functions/get_next_line_bonus.c parse_functions/ft_close_bonus.c\
			parse_functions/get_textures_bonus.c parse_functions/get_map_bonus.c parse_functions/parse_bonus.c parse_functions/error_handler_bonus.c \
			parse_functions/get_playerangle_bonus.c parse_functions/invalid_textures_bonus.c parse_functions/turn_hexa_bonus.c
		
LIBFT = ../libft/ft_strjoin.c ../libft/ft_strlen.c ../libft/ft_strcmp.c \
		../libft/ft_split.c ../libft/ft_memcmp.c ../libft/ft_putstr_fd.c \
		../libft/ft_strdup.c ../libft/ft_substr.c ../libft/ft_atoi.c ../libft/ft_isnum.c \


all: $(NAME)

$(NAME):
	@echo '\033[0;32m'"Use (make bonus) to compile this programm"

bonus:
	@$(CC) $(FLGS) $(MLX) cub3d_bonus.c $(UTLS_BONUS) $(MOVES) $(LIBFT) $(PARSE_FUNC) -o $(NAME)
	@echo '\033[0;32m'"The programm compiled successefully"

clean : 
	rm $(NAME)
	
fclean : clean

re : fclean bonus

.PHONY: re all fclean clean