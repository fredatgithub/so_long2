/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 05:33:20 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/20 08:58:26 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_colum(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

t_map	*map_render(char	*path)
{
	t_map	*land;

	land = malloc(sizeof(t_map));
	if(!land)
		return (NULL);
	land->map = map_validate(path);
	land->x = map_colum(land->map);
	land->y = ft_strlen(land->map[0]);
	land->c = element_count(land->map, 'C');
	land->player = element_position(land->map, 'P');
	return (land);
}