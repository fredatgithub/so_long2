NAME = so_long
CFLAGS = -Wall -Wextra -Werror -I .

SRCS = libft/ft_putstr.c libft/ft_strchr.c libft/ft_strcmp.c libft/ft_strjoin.c \
	   libft/ft_strlen.c libft/ft_strrchr.c libft/ft_split.c libft/ft_strdup.c \
	   libft/ft_memset.c so_long.c \
	   render_map/element_count.c render_map/element_position.c render_map/free_memory.c \
	   render_map/map_render.c render_map/map_validate.c render_map/read_map.c \
	   render_map/validate_content.c render_map/validate_extention.c render_map/validate_path.c \
	   render_map/validate_shape.c srcs/display.c srcs/get_data.c srcs/get_textures_path.c errors.c \
	   render_map/duplicate_map.c moves/up.c event.c moves/down.c  moves/left.c moves/right.c \
	   moves/ft_swap.c \



all : $(NAME)

$(NAME) : 
		cc $(CFLAGS) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean : 
		rm -fr $(NAME)

fclean : clean

re : clean all