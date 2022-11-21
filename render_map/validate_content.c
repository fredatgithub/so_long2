/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:46:36 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/20 08:21:07 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_elements(char **map)
{
	int i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'P' && map[i][j] != 'C'
				&& map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_content(char **map)
{	
	if (!map_elements(map))
	{
		invalid_map_element_error();
		return (0);
	}
	if (element_count(map, 'P') != 1 || element_count(map, 'E') != 1
		|| element_count(map, 'C') < 1)
	{
		missing_map_element_error();
		return (0);
	}
	return (1);
}
