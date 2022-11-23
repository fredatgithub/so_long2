NAME = so_long
BONUS = so_long_bonus
CFLAGS = -Wall -Wextra -Werror -I .

SRCS = libft/ft_putstr.c libft/ft_strcmp.c libft/ft_strjoin.c \
	   libft/ft_strlen.c libft/ft_split.c libft/ft_strdup.c \
	   libft/ft_putnbr.c srcs/so_long.c \
	   render_map/utils/element_count.c render_map/utils/element_position.c render_map/utils/free_memory.c \
	   render_map/map_render.c render_map/map_validate.c render_map/read_map.c \
	   render_map/validate_content.c render_map/validate_extention.c render_map/validate_path.c \
	   render_map/validate_shape.c srcs/display.c srcs/setting_up.c srcs/textures_path.c \
	   render_map/utils/duplicate_map.c moves/up.c srcs/event.c moves/down.c  moves/left.c moves/right.c \
	   moves/ft_swap.c render_map/utils/collectibles_position.c srcs/free_exit.c \
	   errors/function_errors.c errors/map_errors.c \

B_SRCS = libft/ft_putstr.c libft/ft_strcmp.c libft/ft_strjoin.c \
	   libft/ft_strlen.c libft/ft_split.c libft/ft_strdup.c libft/ft_itoa.c \
	   libft/ft_putnbr.c bonus/srcs/so_long_bonus.c \
	   bonus/render_map/utils/element_count.c bonus/render_map/utils/element_position.c \
	   bonus/render_map/utils/free_memory.c \
	   bonus/render_map/map_render_bonus.c bonus/render_map/map_validate.c bonus/render_map/read_map.c \
	   bonus/render_map/validate_content.c bonus/render_map/validate_extention.c \
	   bonus/render_map/validate_path.c \
	   bonus/render_map/validate_shape.c bonus/srcs/display_bonus.c bonus/srcs/setting_up_bonus.c \
	   bonus/srcs/textures_path_bonus.c bonus/render_map/utils/duplicate_map.c \
	   bonus/moves/up_bonus.c bonus/srcs/event_bonus.c bonus/moves/down_bonus.c bonus/moves/left_bonus.c \
	   bonus/moves/right_bonus.c bonus/moves/ft_swap.c bonus/render_map/utils/positions_bonus.c \
	   bonus/srcs/free_exit_bonus.c errors/function_errors.c errors/map_errors.c bonus/srcs/enemy_patrol.c\
	   bonus/player_sprite/player_dir_1.c bonus/player_sprite/player_dir_2.c \

all : $(NAME)

$(NAME) : 
		cc $(CFLAGS) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus : $(BONUS)

$(BONUS) :
		cc $(CFLAGS) $(B_SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(BONUS)

clean : 
		rm -fr $(NAME) $(BONUS)

fclean : clean

re : clean bonus