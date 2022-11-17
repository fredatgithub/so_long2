/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:46:36 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/16 16:39:57 by mtellami         ###   ########.fr       */
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

int	chars_count(char **map, char c)
{
	int i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	validate_content(char **map)
{	
	if (!map_elements(map))
		return (0);
	if (chars_count(map, 'P') != 1 || chars_count(map, 'E') != 1
		|| chars_count(map, 'C') < 1)
		return (0);
	return (1);
}
