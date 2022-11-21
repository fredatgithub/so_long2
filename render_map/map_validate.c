/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:48:41 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/20 10:43:22 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_validate(char *map_path)
{
	char	**map;
	char	**cpy;

	if (!map_extention(map_path))
		exit(0);
	map = read_map(map_path);
	if(!map)
		exit(0);
	cpy = duplicate_map(map);
	if (!validate_content(cpy) || !validate_shape(cpy) || !validate_path(cpy))
	{
		free_map(map);
		free_map(cpy);
		exit(0);
	}
	free(cpy);
	return (map);
}
