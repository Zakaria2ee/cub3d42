# _*_ MakeFile _*_

NAME = cub3d

CC = cc

FLGS = -Wextra -Wall -Werror -O3

FUNC = parse.c render.c

UTLS =  utils/ft_exit.c utils/ft_check_extention.c utils/get_next_line.c \
		utils/get_textures.c utils/get_map.c utils/error_handler.c utils/ft_close.c \
		utils/set_windows.c utils/move_stright.c utils/look_left.c utils/look_right.c \
		utils/move_back.c utils/walls_checker.c utils/rays_counter.c utils/move_left.c \
		utils/move_right.c utils/2d_map_render.c utils/key_hook.c utils/rays_to_image.c \
		utils/rendering_3D_map.c
 
LIBFT = libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strcmp.c \
		libft/ft_split.c libft/ft_memcmp.c libft/ft_putstr_fd.c \
		libft/ft_strdup.c libft/ft_substr.c 


SRCS = 

all: $(NAME)

$(NAME):    $(SRCS)
	@$(CC) $(FLGS) -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit $(FUNC) $(UTLS) $(LIBFT) -fsanitize=address -o $(NAME)

bonus : $(NAME)

clean : 
	rm $(NAME)
	
fclean :	clean

re : fclean all

.PHONY: re all fclean clean