# _*_ MakeFile _*_

NAME = cub3d

CC = cc

FLGS = -Wextra -Wall -Werror -O3

MLX =  -I /usr/local/include  -L /usr/local/lib -pthread -lmlx -framework OpenGL -framework AppKit

PARSE_FUNC = parse_functions/ft_check_extention.c parse_functions/get_next_line.c \
			parse_functions/get_textures.c parse_functions/get_map.c parse_functions/ft_close.c\
			parse_functions/ft_exit.c parse_functions/get_playerangle.c parse_functions/turn_hexa.c\
			parse_functions/error_handler.c parse_functions/parse.c parse_functions/skip_space.c \
			parse_functions/invalid_textures.c
			

MOVES = moves/move_back.c moves/move_stright.c moves/move_left.c moves/move_right.c moves/look_left.c \
		moves/look_right.c

UTLS = utils/render.c  utils/rendering_3D_map.c utils/key_hook.c \
		utils/rays_to_image.c utils/rays_counter.c utils/walls_checker.c  utils/put_black_img.c \
		utils/ft_put_pxl.c 


LIBFT = ../libft/ft_strjoin.c ../libft/ft_strlen.c ../libft/ft_strcmp.c \
		../libft/ft_split.c ../libft/ft_memcmp.c ../libft/ft_putstr_fd.c \
		../libft/ft_strdup.c ../libft/ft_substr.c ../libft/ft_atoi.c ../libft/ft_isnum.c \

all: $(NAME)

$(NAME): $(LIBFT) $(UTLS) $(MOVES) $(PARSE_FUNC)
	@$(CC) $(FLGS) $(MLX) cub3d.c $(LIBFT) $(UTLS) $(MOVES) $(PARSE_FUNC)  -o $(NAME)
	@echo '\033[0;32m'"The programm compiled successefully"

clean : 
	@rm $(NAME)
	
fclean : clean

re : fclean all

.PHONY: re all fclean clean