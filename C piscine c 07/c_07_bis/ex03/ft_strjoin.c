/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:06:06 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/25 11:27:25 by lflandri         ###   ########.fr       */
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

char	*init_str(int size, char **strs, char *sep)
{
	int	str_size;
	int	ind;

	ind = -1;
	str_size = ft_strlen(sep) * (size - 1);
	while (++ind != size)
		str_size += ft_strlen(strs[ind]);
	return (malloc(sizeof(char) * (str_size + 1)));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		ind;
	int		ind_str;
	char	*tempo_sep;

	if (!size)
		return (malloc(0));
	str = init_str(size, strs, sep);
	ind = -1;
	ind_str = 0;
	while (++ind != size)
	{
		while (*(strs[ind]))
			str[ind_str++] = *(strs[ind]++);
		tempo_sep = sep;
		while (*tempo_sep && ind + 1 != size)
			str[ind_str++] = *(tempo_sep++);
	}
	str[ind_str] = 0;
	return (str);
}
