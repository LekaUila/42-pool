/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:12:26 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/23 19:31:10 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "map.h"
#include "final_check.h"

t_bool	ft_recursive(char map[MAP_SIZE][MAP_SIZE], int i, int j);

t_bool	check_column(char map[MAP_SIZE][MAP_SIZE], int j, int ind)
{
	int	move;

	move = -1;
	while (++move != MAP_SIZE)
		if (map[move][j] == ind)
			return (false);
	return (true);
}

t_bool	check_lign(char map[MAP_SIZE][MAP_SIZE], int i, int ind)
{
	int	move;

	move = -1;
	while (++move != MAP_SIZE)
		if (map[i][move] == ind)
			return (false);
	return (true);
}

t_bool	cpmap(char map[MAP_SIZE][MAP_SIZE], int i, int j, int ind)
{
	int		x;
	int		y;
	char	map_copy[MAP_SIZE][MAP_SIZE];

	x = -1;
	while (++x != MAP_SIZE)
	{
		y = -1;
		while (++y != MAP_SIZE)
			map_copy[x][y] = map[x][y];
	}
	if (!(map[i][j]))
		map_copy[i][j] = ind + 1;
	if (j == MAP_SIZE - 1)
		return (ft_recursive(map_copy, i + 1, 0));
	return (ft_recursive(map_copy, i, j + 1));
}

t_bool	ft_recursive(char map[MAP_SIZE][MAP_SIZE], int i, int j)
{	
	int		ind;

	ind = -1;
	if (i == MAP_SIZE)
	{
		if (ft_check_map(map))
		{
			ft_print_map(map);
			return (true);
		}
		return (false);
	}
	if (map[i][j])
	{
		if (cpmap(map, i, j, ind))
			return (true);
	}
	else
	{
		while (++ind != MAP_SIZE)
			if (check_column(map, j, ind + 1) && check_lign(map, i, ind + 1))
				if (cpmap(map, i, j, ind))
					return (true);
	}
	return (false);
}
