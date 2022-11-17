/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:48:41 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/17 15:42:03 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_extention(char *str)
{
	str += ft_strlen(str) - 4;
	if (ft_strcmp(str, ".ber"))
	{
		printf("invalid extention\n");
		return (0);
	}
	return (1);
}

int	map_validate(char *map_path)
{
	char	**map;

	if (!map_extention(map_path))
		return (0);
	map = read_map(map_path);
	if(!map)
	{
		printf("fail reading map\n");
		return (0);
	}
	if (!validate_content(map) || !validate_shape(map)
		|| !validate_path(map))
		return (0);
	free_memory(map);
	return (1);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Wrong number of Args\n");
		return (0);
	}
	if (map_validate(av[1]))
		printf("map is valid");
	else
		printf("invalid map");
}
