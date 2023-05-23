/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:24:01 by lflandri          #+#    #+#             */
/*   Updated: 2022/08/02 20:18:49 by lflandri         ###   ########.fr       */
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

void	starting_crea_map(char *path)
{
	char			*str;
	char			**map;
	t_map_property	map_p_tempo;
	t_map_property	*map_p;
	t_square		square;

	map_p = &map_p_tempo;
	str = ft_filereader(path);
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

char	*add_to_malloc(char *mal, char *str)
{
	char	*new_mal;
	int		ind;

	ind = 0;
	while (mal[ind])
		ind++;
	new_mal = malloc(sizeof(char) * (ind + 2));
	ind = -1;
	while (mal[++ind])
		new_mal[ind] = mal[ind];
	new_mal[ind] = *str;
	new_mal[ind + 1] = 0;
	free(mal);
	return (new_mal);
}

void	read_standart_entry(void)
{
	char	str[1];
	char	*mal;
	int		size;

	mal = malloc(sizeof(char));
	*mal = '\0';
	size = 1;
	while (size == 1)
	{
		size = read(1, str, 1);
		if (*str == '\n')
			break ;
		mal = add_to_malloc(mal, str);
	}
	starting_crea_map(mal);
	free(mal);
}

int	main(int ac, char **av)
{
	int	ind;

	if (ac != 1)
	{
		ind = 0;
		while (++ind != ac)
			starting_crea_map(av[ind]);
	}
	else
		read_standart_entry();
	return (0);
}
