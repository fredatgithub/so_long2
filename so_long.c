/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:17:37 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/15 15:26:45 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	if (ac > 2)
		return (0);
	if (!map_validate(av[1]))
	{
		ft_putstr("invalid map !", 1);
		return (0);
	}
	// minilibix
}