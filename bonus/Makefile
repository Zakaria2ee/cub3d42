# _*_ MakeFile _*_

NAME = cub3d_bonus

CC = cc

FLGS = -Wextra -Wall -Werror -O3

MLX =  -I /usr/local/include  -L /usr/local/lib -pthread -lmlx -framework OpenGL -framework AppKit

UTLS_BONUS =  utils_bonus/put_black_img.c utils_bonus/ft_put_pxl.c \
			utils_bonus/rendering_3dbonus_map.c utils_bonus/render_bonus.c \
			utils_bonus/bonus_key_hook.c utils_bonus/minimap.c utils_bonus/rays_to_image_b.c utils_bonus/walls_checker.c \
			utils_bonus/rays_counter_b.c utils_bonus/door.c utils_bonus/key_press.c utils_bonus/key_release.c  \

MOVES = moves/look_left.c moves/look_right.c moves/move_left.c moves/move_right.c moves/move_stright_back.c\
		 

PARSE_FUNC = parse_functions/ft_exit.c parse_functions/ft_check_extention.c parse_functions/get_next_line.c parse_functions/ft_close.c\
			parse_functions/get_textures.c parse_functions/get_map.c parse_functions/parse_bonus.c parse_functions/error_handler.c \
			parse_functions/get_playerangle.c
		
LIBFT = ../libft/ft_strjoin.c ../libft/ft_strlen.c ../libft/ft_strcmp.c \
		../libft/ft_split.c ../libft/ft_memcmp.c ../libft/ft_putstr_fd.c \
		../libft/ft_strdup.c ../libft/ft_substr.c ../libft/ft_atoi.c ../libft/ft_isnum.c \


all: $(NAME)

$(NAME):
	@echo '\033[0;32m'"Use (make bonus) to compile this programm"

bonus:
	@$(CC) $(FLGS) $(MLX) cub3d_bonus.c $(UTLS_BONUS) $(MOVES) $(LIBFT) $(PARSE_FUNC) -fsanitize=address -o $(NAME)
	@echo '\033[0;32m'"The programm compiled successefully"

clean : 
	rm $(NAME)
	
fclean : clean

re : fclean bonus

.PHONY: re all fclean clean