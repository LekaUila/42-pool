/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predictable_optimisations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:30:58 by maldavid          #+#    #+#             */
/*   Updated: 2022/07/23 15:08:28 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	ft_natural_way(char map[MAP_SIZE][MAP_SIZE], int i, int j)
{
	int	k;

	k = -1;
	while (++k < MAP_SIZE)
	{
		if (i < 2)
				map[k][j] = k + 1;
		else
				map[j][k] = k + 1;
	}
}

void	ft_unnatural_way(char map[MAP_SIZE][MAP_SIZE], int i, int j)
{
	int	k;
	int	l;

	k = MAP_SIZE;
	l = 0;
	while (--k > -1)
	{
		if (i < 2)
				map[k][j] = l + 1;
		else
				map[j][k] = l + 1;
		l++;
	}
}

void	ft_border_four(char map[MAP_SIZE][MAP_SIZE], int i, int j)
{
	if (i == 0)
		map[0][j] = MAP_SIZE;
	else if (i == 1)
		map[3][j] = MAP_SIZE;
	else if (i == 2)
		map[j][0] = MAP_SIZE;
	else if (i == 3)
		map[j][3] = MAP_SIZE;
}

void	ft_predictable_optimisations(char map[MAP_SIZE][MAP_SIZE],
									char borders[MAP_SIZE][MAP_SIZE])
{
	int	i;
	int	j;

	i = -1;
	while (++i < MAP_SIZE)
	{
		j = -1;
		while (++j < MAP_SIZE)
		{
			if (borders[i][j] == MAP_SIZE)
			{
				if (i % 2 == 0)
					ft_natural_way(map, i, j);
				else
					ft_unnatural_way(map, i, j);
			}
			else if (borders[i][j] == 1)
				ft_border_four(map, i, j);
		}
	}
}
