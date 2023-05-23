/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:24:01 by lflandri          #+#    #+#             */
/*   Updated: 2022/08/03 14:29:29 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_map(char **map)
{
	char	**map_adress;

	map -= 1;
	map_adress = map;
	while (**map != 0)
	{
		free(*map);
		map++;
	}
	free(map_adress);
}

void	starting_crea_map(char *path, char *str)
{
	char			**map;
	t_map_property	map_p_tempo;
	t_map_property	*map_p;
	t_square		square;

	map_p = &map_p_tempo;
	if (str == NULL)
		str = ft_filereader(path);
	if (ft_strlen(str) <= 4)
	{
		free(str);
		write(2, "map error\n", 10);
		return ;
	}
	map = ft_atomap(str, map_p);
	free(str);
	if (map != NULL)
	{
		square = point_checker(map, *map_p);
		replace_map(map, square, *map_p);
		write_map(map, *map_p);
		free_map(map);
	}
	else
		write(2, "map error\n", 10);
}

int	main(int ac, char **av)
{
	int	ind;

	if (ac != 1)
	{
		ind = 0;
		while (++ind != ac)
		{
			starting_crea_map(av[ind], NULL);
			if (ind + 1 != ac)
				write(1, "\n", 1);
		}
	}
	else
		read_standart_entry();
	return (0);
}
