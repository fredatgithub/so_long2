/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:43:29 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/17 11:08:19 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

// libft
void	ft_putstr(char *str, int fd);
char	*ft_strchr(const char *str, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strrchr(const char *str, int c);
char	*ft_strdup(char *str);
void	*ft_memset(void *s, int c, size_t n);

// check map validation
char	**ft_split(char const *s, char c);
char	**read_map(char *map_path);
int		validate_shape(char **map);
int		validate_content(char **map);
void	free_memory(char **map);
int	validate_path(char **map);

typedef struct s_position
{
	int x;
	int	y;	
}	t_position;



#endif