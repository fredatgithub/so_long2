/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:43:29 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/20 16:16:39 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ------ C Library ------ */
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

/* --------------- Libft --------------- */
void	ft_putstr(char *str, int fd);
char	*ft_strchr(const char *str, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strrchr(const char *str, int c);
char	*ft_strdup(char *str);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c);

/* ------------ Structures ------------ */
typedef struct s_pos
{
	int x;
	int y;
}	t_pos;

typedef struct s_map
{
	char 	**map;
	int		x;
	int		y;
	int		c;
	t_pos	*player;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	t_map	*map;
	int	size;
	int	moves;
}	t_game;

/* ------------ Map Render ------------ */
int	element_count(char **map, char c);
t_pos	*element_position(char **map, char c);
void	free_map(char **map);
t_map	*map_render(char	*path);
char	**map_validate(char *map_path);
char	**read_map(char *map_path);
int	validate_content(char **map);
int	map_extention(char *str);
int	validate_path(char **map);
int	validate_shape(char **map);
char	**duplicate_map(char **map);

void	display(t_game	*so_long);
t_game	*setting_up(t_map *map);
char	*get_textures_path(char c);


/* ------------ Errors ------------ */
void	extention_error();
void	map_shape_error();
void	read_fail_error();
void	open_fail_error();
void	invalid_map_element_error();
void	missing_map_element_error();
void	non_rectangle_map_error();
void	non_closed_map_error();
void	invalid_number_of_argument();
void	fail_rendering_map();

/* ------------ Moves ------------ */
void	up(t_game *so_long);
void	down(t_game *so_long);
void	left(t_game *so_long);
void	right(t_game *so_long);
void	ft_swap(char *a, char *b);
int	event(int key, void	*param);
/* ------------ So_long ------------ */


#endif