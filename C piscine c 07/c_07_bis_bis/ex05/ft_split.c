/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:32:49 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/28 17:21:26 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	char_int_charset(char *charset, char charr)
{
	while (*charset)
	{
		if (*(charset++) == charr)
			return (1);
	}
	return (0);
}

int	count_str(char *str, char *charset)
{
	int	count;
	int	boo;

	boo = 0;
	count = 0;
	while (*str)
	{
		if (char_int_charset(charset, *str))
				boo = 0;
		else
		{
			if (!boo)
			{
				boo = 1;
				count++;
			}
		}
		str++;
	}
	return (count);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 1;
	while (*str && !char_int_charset(charset, *str))
	{
		i++;
		str++;
	}
	return (i);
}

char	*create_new_str(char *str, char *charset)
{
	char	*string_save;
	char	*string;

	string = malloc(sizeof(*str) * (ft_strlen(str, charset)));
	string_save = string;
	while (*str && !(char_int_charset(charset, *str)))
	{
		*string = *str;
		string++;
		str++;
	}
	*string = '\0';
	return (string_save);
}

char	**ft_split(char *str, char *charset)
{
	char	boo;
	char	**tab;
	int		ind;

	ind = 0;
	tab = malloc(sizeof(char *) * (count_str(str, charset) + 1));
	boo = 0;
	while (*str)
	{
		if (char_int_charset(charset, *str))
				boo = 0;
		else
		{
			if (!boo)
			{
				boo = 1;
				tab[ind] = create_new_str(str, charset);
				ind++;
			}
		}
		str++;
	}
	tab[ind] = 0;
	return (tab);
}
