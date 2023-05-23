/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:45:59 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/31 12:27:03 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr_return(char *str, char *to_find)
{
	free(to_find);
	return (str);
}

char	*ft_add0(int z_nbr, char nbr)
{
	char	*str;
	int		y;

	y = 0;
	str = malloc(sizeof(char) * z_nbr + 2);
	str[0] = nbr;
	while (++y < z_nbr + 1)
		str[y] = '0';
	str[y] = '\0';
	return (str);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	verif;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			i = 0;
			verif = 0;
			while (*(to_find + i))
			{
				if (*(to_find + i) != *(str + i))
					verif = 1;
				i++;
			}
			if (*(str + i) != ':' && *(str - 1) == '\n')
				verif = 1;
			if (verif == 0)
				return (str);
		}
		str++;
	}
	return (0);
}
