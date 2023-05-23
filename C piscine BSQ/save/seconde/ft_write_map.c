/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:30:49 by cchauvet          #+#    #+#             */
/*   Updated: 2022/08/02 14:17:24 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void replace_map(char **map, t_square squarre, t_map_property map_p)
{
	int x;
	int y;

	y = squarre.y - 1;
	while (++y != squarre.size)
	{
		x = squarre.x - 1;
		while (++x != squarre.size)
		{
			map[y][x] = map_p.full;
		}
		
	}
}

void write_map(char **map, t_map_property map_p)
{    
    unsigned x;
    unsigned y;
    
    y = -1;
    while (++y != map_p.v_len)
    {
        x = -1;
        while (++x != map_p.h_len)
            write(1, map[y] + x, 1);
        write(1, "\n", 1);
    }
}
