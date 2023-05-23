/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlauvray <nlauvray@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:41:20 by nlauvray          #+#    #+#             */
/*   Updated: 2022/07/31 20:50:52 by cchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	**ft_split(char *str, char *sep)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	tab = malloc(sizeof(*str) * ft_strlen(str));
	while (str[i] != 0 && ft_strlen(str) > i)
	{
		k = i;
		tab[j] = malloc(sizeof(**tab) * (i - k + ft_strstr(&str[i], sep) + 1));
		while (i < k + ft_strstr(&str[k], sep))
		{
			tab[j][i - k] = str[i];
			i++;
		}
		tab[j][i - k] = '\0';
		i = k + ft_strstr(&str[k], sep) + ft_strlen(sep);
		j++;
	}
	tab[j] = malloc(sizeof(char));
	tab[j] = "";
	return (tab);
}
