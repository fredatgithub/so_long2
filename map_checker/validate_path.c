/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:09:42 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/17 15:06:45 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_position	*position(char **map, char c)
{
	t_position	*p;
	int	i;
	int	j;

	p = malloc(sizeof(t_position));
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				p->x = i;
				p->y = j;
			}
			j++;
		}
		i++;
	}
	return (p);
}

int	check_steps(char **map, int x, int y, t_position *E)
{
	if (map[x][y] == '1')
		return (0);
	if (x == E->x && y == E->y)
		return (1);
	if (check_steps(map, x + 1, y, E))
		return (1);	
	else
		map[x][y] = '1';
	if (check_steps(map, x - 1, y, E))
		return (1);
	else
		map[x][y] = '1';
	if (check_steps(map, x, y + 1, E))
		return (1);
	else
		map[x][y] = '1';
	if (check_steps(map, x, y - 1, E))
		return (1);
	else
		map[x][y] = '1';
	return (0);
}

int	validate_path(char **map)
{
	t_position	*P;
	t_position	*E;

	E = position(map, 'E');
	P = position(map, 'P');
	if(check_steps(map, P->x, P->y, E))
		return (1);
	free(P);
	free(E);
	return (0);
}
