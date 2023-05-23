/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 12:17:11 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/24 12:17:15 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	reset_counter(int max_values[2], int counters[2])
{
	max_values[0] = 0;
	counters[0] = 0;
	max_values[1] = 0;
	counters[1] = 0;
}

void	ft_check_map_step1_bis(int coor[2], int max_values[2],
						int counters[2], char map[MAP_SIZE][MAP_SIZE])
{
	if (map[coor[0]][coor[1]] > max_values[0])
	{
		max_values[0] = map[coor[0]][coor[1]];
		counters[0]++;
	}
	if (map[coor[0]][MAP_SIZE - 1 - coor[1]] > max_values[1])
	{
		max_values[1] = map[coor[0]][MAP_SIZE - 1 - coor[1]];
		counters[1]++;
	}
}

void	ft_check_map_step2_bis(int coor[2], int max_values[2],
						int counters[2], char map[MAP_SIZE][MAP_SIZE])
{
	if (map[coor[0]][coor[1]] > max_values[0])
	{
		max_values[0] = map[coor[0]][coor[1]];
		counters[0]++;
	}
	if (map[MAP_SIZE - 1 - coor[0]][coor[1]] > max_values[1])
	{
		max_values[1] = map[MAP_SIZE - 1 - coor[0]][coor[1]];
		counters[1]++;
	}
}

void	ft_check_map_step1(int i, int max_values[2],
						int counters[2], char map[MAP_SIZE][MAP_SIZE])
{
	int	coor[2];

	coor[0] = i;
	coor[1] = -1;
	while (++coor[1] < MAP_SIZE)
	{
		ft_check_map_step1_bis(coor, max_values, counters, map);
	}
}

void	ft_check_map_step2(int i, int max_values[2],
						int counters[2], char map[MAP_SIZE][MAP_SIZE])
{
	int	coor[2];

	coor[0] = -1;
	coor[1] = i;
	while (++coor[0] < MAP_SIZE)
	{
		ft_check_map_step2_bis(coor, max_values, counters, map);
	}
}
