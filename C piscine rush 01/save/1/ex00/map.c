/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:09:17 by maldavid          #+#    #+#             */
/*   Updated: 2022/07/23 16:09:17 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parser.h"
#include "predictable_optimisations.h"
#include "fucking_recursive.h"

static char	g_map[MAP_SIZE][MAP_SIZE];
static char	g_map_borders[MAP_SIZE][MAP_SIZE];

void	ft_init_map(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < MAP_SIZE)
	{
		j = 0;
		while (j < MAP_SIZE)
		{
			g_map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_check_map_step(int i, int j, int max_values[MAP_SIZE],
						int counters[MAP_SIZE], char map[MAP_SIZE][MAP_SIZE])
{
	if (map[j][i] > max_values[0])
	{
		max_values[0] = map[j][i];
		counters[0]++;
	}
	if (map[MAP_SIZE - 1 - j][MAP_SIZE - 1 - i] > max_values[1])
	{
		max_values[1] = map[MAP_SIZE - 1 - j][MAP_SIZE - 1 - i];
		counters[1]++;
	}
	if (map[i][j] > max_values[2])
	{
		max_values[2] = map[i][j];
		counters[2]++;
	}
	if (map[MAP_SIZE - 1 - i][MAP_SIZE - 1 - j] > max_values[3])
	{
		max_values[3] = map[MAP_SIZE - 1 - i][MAP_SIZE - 1 - j];
		counters[3]++;
	}
}

t_bool	ft_check_map(char map[MAP_SIZE][MAP_SIZE])
{
	int	i;
	int	j;
	int	max_values[MAP_SIZE];
	int	counters[MAP_SIZE];

	i = -1;
	while (++i < MAP_SIZE)
	{
		j = -1;
		while (++j < MAP_SIZE)
		{
			counters[j] = 0;
			max_values[j] = 0;
		}
		j = -1;
		while (++j < MAP_SIZE)
			ft_check_map_step(i, j, max_values, counters, map);
		j = -1;
		while (++j < MAP_SIZE)
			if (counters[j] != g_map_borders[i][j])
				return (0);
	}
	return (1);
}

t_bool	ft_fill_map(char *border_values)
{
	int	i;
	int	j;

	ft_parse_map(g_map_borders, border_values);
	ft_predictable_optimisations(g_map, g_map_borders);
	//i = -1;
	ft_recursive(g_map, 0, 0);
/*
	while (++i < MAP_SIZE)
	{
		j = -1;
		while (++j < MAP_SIZE)
		{
		}
	}
	if (!ft_check_map())
	{
		write(1, "Error\n", 6);
		return (false);
	}
	return (true);*/
}

void	ft_print_map(void)
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
			c = g_map[i][j];
			write(1, &c, 1);
			if (j != MAP_SIZE - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
