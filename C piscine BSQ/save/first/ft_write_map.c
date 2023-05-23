/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvet <cchauvet@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:30:49 by cchauvet          #+#    #+#             */
/*   Updated: 2022/08/02 11:31:05 by cchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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
