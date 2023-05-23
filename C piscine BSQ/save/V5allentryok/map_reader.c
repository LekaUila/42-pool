/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:13:40 by cchauvet          #+#    #+#             */
/*   Updated: 2022/08/03 09:41:52 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_map_property	ft_map_error(void)
{
	t_map_property	property;

	property.full = 0;
	property.obstacle = 0;
	property.clear = 0;
	property.h_len = 0;
	property.v_len = 0;
	return (property);
}

t_map_property	property_return_error(char *lines_counter)
{
	free(lines_counter);
	return (ft_map_error());
}

t_map_property	ft_get_map_property(char **lines)
{
	t_map_property	property;
	char			*lines_counter;
	unsigned int	i;

	if (!(ft_strlen(lines[0]) >= 4))
		return (ft_map_error());
	lines_counter = ft_strndup(lines[0], ft_strlen(lines[0]) - 2);
	if (!ft_is_digit(lines_counter))
		return (property_return_error(lines_counter));
	if (ft_tablen(&lines[1]) != ft_atou(lines_counter))
		return (property_return_error(lines_counter));
	i = 2;
	while (ft_strlen(lines[1]) == ft_strlen(lines[i]))
		i++;
	if (i != ft_tablen(lines))
		return (property_return_error(lines_counter));
	property.full = lines[0][ft_strlen(lines[0]) - 1];
	property.obstacle = lines[0][ft_strlen(lines[0]) - 2];
	property.clear = lines[0][ft_strlen(lines[0]) - 3];
	property.v_len = ft_atou(lines_counter);
	property.h_len = ft_strlen(lines[1]);
	free(lines_counter);
	return (property);
}

char	**ft_atomap(char *str, t_map_property *property)
{
	char			**lines;

	lines = ft_split(str, "\n");
	*property = ft_get_map_property(lines);
	if (ft_mapcmp(*property, ft_map_error()) != 0)
	{
		free_map(&lines[1]);
		return (NULL);
	}
	if (ft_contain_only(&lines[1], &lines[0][ft_strlen(lines[0]) - 3]) == 0)
	{
		free_map(&lines[1]);
		return (NULL);
	}
	return (&lines[1]);
}
