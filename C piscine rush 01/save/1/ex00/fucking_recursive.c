/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fucking_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:12:26 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/23 16:12:27 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "map.h"

char	ft_recursive(char map[MAP_SIZE][MAP_SIZE], int i, int j);

char	check_column(char map[MAP_SIZE][MAP_SIZE], int j, int ind)
{
	int	move;

	move = -1;
	while (++move != MAP_SIZE)
		if (map[move][j] == ind)
			return (0);
	return (1);
}

char	check_lign(char map[MAP_SIZE][MAP_SIZE], int i, int ind)
{
	int	move;

	move = -1;
	while (++move != MAP_SIZE)
		if (map[i][move] == ind)
			return (0);
	return (1);
}

void	ft_print_map2(char map[MAP_SIZE][MAP_SIZE])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < MAP_SIZE)
	{
		j = 0;
		while (j < MAP_SIZE)
		{
			c = map[i][j] + 48;
			write(1, &c, 1);
			if (j != MAP_SIZE - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

char	cpmap(char map[MAP_SIZE][MAP_SIZE], int i, int j, int ind)
{
	int		x;
	int		y;
	char	map_copy[MAP_SIZE][MAP_SIZE];

	x = 0;
	while (x != MAP_SIZE)
	{
		y = -1;
		while (++y != MAP_SIZE)
			map_copy[x][y] = map[x][y];
		x++;
	}
	if (!(map[i][j]))
		map_copy[i][j] = ind + 1;
	if (j == MAP_SIZE)
		return (ft_recursive(map_copy, i + 1, 0));
	else
		return (ft_recursive(map_copy, i, j + 1));

}

char	ft_recursive(char map[MAP_SIZE][MAP_SIZE], int i, int j)
{	
	int		ind;
	char	boo;
	write(1, "entree\n", 7);
	ind = -1;
	if (i == 4)
	{	if (map[3][3] == 3 && map[3][2] == 2 && map[3][1] == 1 && map[2][3] == 2 && map[2][2] == 1 && map[2][1] == 4 && map[1][3] == 1 && map[1][2] == 4 && map[1][1] == 3)
		{
			ft_print_map2(map);
			write(1, "\n", 1);
		}
		if (ft_check_map(map))
		{
			ft_print_map2(map);
			return (1);
		}
		return (0);
	}
	if (map[i][j])
	{
		boo = cpmap(map, i, j, ind);
			if (boo)
				return (1);
	}
	else
	{
	while (++ind != MAP_SIZE)
	{
		if (check_column(map, j, ind + 1) && check_lign(map, i, ind + 1))
		{
			boo = cpmap(map, i, j, ind);
			if (boo)
				return (1);
		}
	}
	}
	write(1, "sortie\n", 7);
	return (0);
}
