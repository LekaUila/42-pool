/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:30:49 by cchauvet          #+#    #+#             */
/*   Updated: 2022/08/02 18:40:55 by cchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	write_map(char **map, t_map_property map_p)
{
	unsigned int	x;
	unsigned int	y;

	y = -1;
	while (++y != map_p.v_len)
	{
		x = -1;
		while (++x != map_p.h_len)
			write(1, map[y] + x, 1);
		write(1, "\n", 1);
	}
}

void	replace_map(char **map, t_square squarre, t_map_property map_p)
{
	int	x;
	int	y;

	y = squarre.y - 1;
	while (++y != squarre.size + squarre.y)
	{
		x = squarre.x - 1;
		while (++x != squarre.size + squarre.x)
		{
			map[y][x] = map_p.full;
		}
	}
}
