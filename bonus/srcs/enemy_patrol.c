/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:13:13 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/23 11:37:19 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_moves(t_game *so_long, int i, int x, int y)
{
	static int	move;

	if (move <= so_long->map->y)
	{
		if (so_long->map->map[x][y + 1] == '0')
		{
			ft_swap(&so_long->map->map[x][y + 1], &so_long->map->map[x][y]);
			so_long->map->enemy[i]->y++;
		}
		else if (so_long->map->map[x][y + 1] == 'P')
			free_exit_bonus(so_long);
		else
			move = so_long->map->y;
	}
	else if (move > so_long->map->y && move < so_long->map->y * 2)
	{
		if (so_long->map->map[x][y - 1] == '0')
		{
			ft_swap(&so_long->map->map[x][y - 1], &so_long->map->map[x][y]);
			so_long->map->enemy[i]->y--;
		}
		else if (so_long->map->map[x][y - 1] == 'P')
			free_exit_bonus(so_long);
		else
			move = move < so_long->map->y * 2;
	}
	else
		move = -1;
	move++;
}

int	enemy_patrol(void *param)
{
	t_game	*so_long;
	int		i;
	int		count;
	int		x;
	int		y;

	so_long = (t_game *)param;
	i = 0;
	mlx_clear_window(so_long->mlx, so_long->win);
	count = element_count(so_long->map->map, 'X');
	while (i < count)
	{
		x = so_long->map->enemy[i]->x;
		y = so_long->map->enemy[i]->y;
		enemy_moves(so_long, i, x, y);
		i++;
	}
	display_bonus(so_long);
	return (1);
}
