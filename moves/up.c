/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:10:09 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/20 17:00:27 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_game *so_long)
{
	if (so_long->map->map[so_long->map->player->x - 1][so_long->map->player->y] == '1')
		return ;
	if (so_long->map->map[so_long->map->player->x - 1][so_long->map->player->y] == '0')
	{
		ft_swap(&so_long->map->map[so_long->map->player->x - 1][so_long->map->player->y], &so_long->map->map[so_long->map->player->x][so_long->map->player->y]);
		so_long->map->player->x--;
		so_long->moves++;
		printf("%d\n", so_long->moves);
	}
	else if (so_long->map->map[so_long->map->player->x - 1][so_long->map->player->y] == 'C')
	{
		ft_swap(&so_long->map->map[so_long->map->player->x - 1][so_long->map->player->y], &so_long->map->map[so_long->map->player->x][so_long->map->player->y]);
		so_long->map->map[so_long->map->player->x][so_long->map->player->y] = '0';
		so_long->map->c--;
		so_long->map->player->x--;
		so_long->moves++;
		printf("%d\n", so_long->moves);
	}
	else if (so_long->map->map[so_long->map->player->x - 1][so_long->map->player->y] == 'E')
	{
		if (so_long->map->c == 0)
			exit(0);
	}
}
