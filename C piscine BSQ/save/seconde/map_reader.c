/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:13:40 by cchauvet          #+#    #+#             */
/*   Updated: 2022/08/02 14:35:14 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_map_property	ft_map_error()
{
	t_map_property	property;

	property.full = 0;
	property.obstacle = 0;
	property.clear = 0;
	property.h_len = 0;
	property.v_len = 0;
	return (property);
}

t_map_property	ft_get_map_property(char **lines)
{
	t_map_property	property;
	char			*lines_counter;
	unsigned int	i;

	if (!(ft_strlen(lines[0]) >= 4))
		return (ft_map_error());	
	lines_counter = ft_strndup(lines[0], ft_tablen(lines) - 3);
	if (!ft_is_digit(&lines_counter[1]))
		return (ft_map_error());
	if (ft_tablen(lines) != ft_atou(lines_counter))
		return (ft_map_error());
	i = 2;
	while (ft_strlen(lines[1]) == ft_strlen(lines[i]))
		i++;
	if (i != ft_tablen(lines))
		return (ft_map_error());
	property.full = lines[0][ft_strlen(lines[0]) - 1];
	property.obstacle = lines[0][ft_strlen(lines[0]) - 2];
	property.clear = lines[0][ft_strlen(lines[0]) - 3];
	property.v_len = ft_atou(lines_counter);
	property.h_len = ft_strlen(lines[1]);
	return (property);
}

char	**ft_atomap(char *str, t_map_property *property)
{
	char			**lines;

	lines = ft_split(str, "\n");
	*property = ft_get_map_property(lines);
	if (*property == ft_map_error())
		return (NULL);
	if (ft_containe_only(&lines[1], &lines[0][ft_strlen(lines[0]) - 3]) == 0)
		return (NULL);
	return (&lines[1]);
}
