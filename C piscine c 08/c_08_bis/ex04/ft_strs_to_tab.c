/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 09:32:46 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/27 19:05:46 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != 0)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	char	*dest_tempo;

	dest = malloc(sizeof(*src) * (ft_strlen(src) + 1));
	dest_tempo = dest;
	while (*src != 0)
	{
		*dest_tempo = *src;
		src++;
		dest_tempo++;
	}
	*dest_tempo = 0;
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			ind;

	ind = -1;
	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	while (++ind != ac)
	{
		tab[ind].size = ft_strlen(av[ind]);
		tab[ind].str = av[ind];
		tab[ind].copy = ft_strdup(av[ind]);
	}
	tab[ind].size = 0;
	tab[ind].str = 0;
	tab[ind].copy = 0;
	return (tab);
}
