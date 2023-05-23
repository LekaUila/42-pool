/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:45:59 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/31 14:47:51 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_rev_char_tab(char *tab, int size)
{
	int		i;
	char	temp;

	i = size;
	while (i != size / 2)
	{
		temp = tab[size - i];
		tab[size - i] = tab[i - 1];
		tab[i - 1] = temp;
		i--;
	}
	return (tab);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

char	*ft_strchar(char *str, char to_find)
{
	while (*str)
	{
		if (*str == to_find)
		{
			if (*(str + 1) == ':' && *(str - 1) == '\n')
				return (str);
		}
		str++;
	}
	return (0);
}

void	ft_putnbr(char *str, char *del_space)
{
	if (*del_space)
		write(1, " ", 1);
	else
		*del_space = 1;
	while (*str != ':')
		str++;
	str++;
	while (*str == ' ')
		str++;
	while (*str != '\n')
		write(1, str++, 1);
}
