/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:41:20 by nlauvray          #+#    #+#             */
/*   Updated: 2022/08/03 17:34:23 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**ft_split(char *str, char *sep)
{
	char				**tab;
	unsigned int		i;
	unsigned int		j;
	unsigned int		k;

	i = 0;
	j = 0;
	tab = malloc(sizeof(str) * ft_strlen(str));
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
	tab[j] = "";
	return (tab);
}
