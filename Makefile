NAME = so_long
CFLAGS = -Wall -Wextra -Werror -I .

SRCS = map_checker/map_validate.c map_checker/read_map.c map_checker/validate_content.c \
	   map_checker/validate_shape.c libft/ft_putstr.c libft/ft_strchr.c \
	   libft/ft_strcmp.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strrchr.c \
	   libft/ft_split.c map_checker/free_memory.c libft/ft_memset.c \
	   libft/ft_strdup.c map_checker/validate_path.c \


all : $(NAME)

$(NAME) : 
		cc $(CFLAGS) $(SRCS) -o $(NAME)

clean : 
		rm -fr $(NAME)

re : clean all