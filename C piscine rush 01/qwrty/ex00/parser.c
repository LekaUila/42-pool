/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:29:29 by maldavid          #+#    #+#             */
/*   Updated: 2022/07/23 14:14:42 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_parse_map(char map[MAP_SIZE][MAP_SIZE], char *border_values)
{
	int	i;
	int	j;

	i = 0;
	while (border_values && i < MAP_SIZE)
	{
		j = 0;
		while (border_values && j < MAP_SIZE)
		{
			if (*border_values != ' ')
			{
				map[i][j] = *border_values - 48;
				j++;
			}
			border_values++;
		}
		i++;
	}
}
