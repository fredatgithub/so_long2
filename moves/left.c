/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:14:24 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/20 17:02:43 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left(t_game *so_long)
{
	if (so_long->map->map[so_long->map->player->x][so_long->map->player->y - 1] == '1')
		return ;
	if (so_long->map->map[so_long->map->player->x][so_long->map->player->y - 1] == '0')
	{
		ft_swap(&so_long->map->map[so_long->map->player->x][so_long->map->player->y - 1], &so_long->map->map[so_long->map->player->x][so_long->map->player->y]);
		so_long->map->player->y--;
		so_long->moves++;
		printf("%d\n", so_long->moves);
	}
	else if (so_long->map->map[so_long->map->player->x][so_long->map->player->y - 1] == 'C')
	{
		ft_swap(&so_long->map->map[so_long->map->player->x][so_long->map->player->y - 1], &so_long->map->map[so_long->map->player->x][so_long->map->player->y]);
		so_long->map->map[so_long->map->player->x][so_long->map->player->y] = '0';
		so_long->map->c--;
		so_long->map->player->y--;
		so_long->moves++;
		printf("%d\n", so_long->moves);
	}
	else if (so_long->map->map[so_long->map->player->x][so_long->map->player->y - 1] == 'E')
		if (so_long->map->c == 0)
			exit(0);
}
