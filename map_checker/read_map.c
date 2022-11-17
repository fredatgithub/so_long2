/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:26:29 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/16 16:04:21 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*reading(int fd)
{
	char	*map;
	char	*buffer;
	int	i;

	buffer = malloc(sizeof(char) * 11);
	map = NULL;
	i = 1;
	while (i)
	{
		i = read(fd, buffer, 10);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		map = ft_strjoin(map, buffer);
	}
	free(buffer);
	return (map);
}

char	**read_map(char *map_path)
{
	char	**map;
	char	*str;
	int	fd;
	
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		printf("fail reading map");
		return (NULL);
	}
	str = reading(fd);
	if (!str)
		return (NULL);
	close(fd);
	map = ft_split(str, '\n');
	if (!map)
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (map);
}
