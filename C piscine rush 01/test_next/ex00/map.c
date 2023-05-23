/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:09:17 by maldavid          #+#    #+#             */
/*   Updated: 2022/07/23 19:58:49 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "backtracker.h"
#include "parser.h"
#include "final_check.h"
#include "predictable_optimisations.h"

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

t_bool	ft_check_map(char map[MAP_SIZE][MAP_SIZE])
{
	int	i;
	int	j;
	int	max_values[2];
	int	counters[2];

	i = -1;
	while (++i < MAP_SIZE)
	{
		reset_counter(counters, max_values);
		ft_check_map_step1(i, max_values, counters, map);
		if (counters[0] != g_map_borders[2][i]
			|| counters[1] != g_map_borders[3][i])
			return (false);
	}
	i = -1;
	while (++i < MAP_SIZE)
	{
		reset_counter(counters, max_values);
		ft_check_map_step2(i, max_values, counters, map);
		if (counters[0] != g_map_borders[0][i]
			|| counters[1] != g_map_borders[1][i])
			return (false);
	}
	return (true);
}

t_bool	ft_fill_map(char *border_values)
{
	ft_parse_map(g_map_borders, border_values);
	ft_predictable_optimisations(g_map, g_map_borders);
	if (!ft_recursive(g_map, 0, 0))
	{
		write(1, "Error\n", 6);
		return (false);
	}
	return (true);
}

void	ft_print_map(char map[MAP_SIZE][MAP_SIZE])
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < MAP_SIZE)
	{
		j = -1;
		while (++j < MAP_SIZE)
		{
			c = map[i][j] + '0';
			write(1, &c, 1);
			if (j != MAP_SIZE - 1)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}
