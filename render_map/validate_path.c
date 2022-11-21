/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:09:42 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/20 08:55:02 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_valid_path(char **map, int x, int y, t_pos *E)
{
	if (map[x][y] == '1')
		return (0);
	if (x == E->x && y == E->y)
		return (1);
	if (check_valid_path(map, x + 1, y, E))
		return (1);	
	else
		map[x][y] = '1';
	if (check_valid_path(map, x - 1, y, E))
		return (1);
	else
		map[x][y] = '1';
	if (check_valid_path(map, x, y + 1, E))
		return (1);
	else
		map[x][y] = '1';
	if (check_valid_path(map, x, y - 1, E))
		return (1);
	else
		map[x][y] = '1';
	return (0);
}

int	validate_path(char **map)
{
	t_pos	*P;
	t_pos	*E;

	E = element_position(map, 'E');
	P = element_position(map, 'P');
	if(check_valid_path(map, P->x, P->y, E))
		return (1);
	free(P);
	free(E);
	return (0);
}
