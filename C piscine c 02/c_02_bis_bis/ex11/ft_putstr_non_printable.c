/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 08:48:39 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/17 08:48:40 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_int_to_hexa(char str, char *tab)
{	
	char	table[16];
	int		n;

	n = -1;
	while (++n < 10)
		table[n] = n + 48;
	n = -1;
	while (++n < 6)
		table[n + 10] = 97 + n;
	tab[0] = table[str / 16];
	tab[1] = table[str % 16];
	return (tab);
}

void	ft_putstr_non_printable(char *str)
{
	char	tab[2];
	char	*rep;

	while (*str != 0)
	{
		if (*str < 32 || *str == 127)
		{
			rep = ft_int_to_hexa(*str, tab);
			write(1, "\\", 1);
			write(1, rep, 1);
			write(1, rep + 1, 1);
		}
		else
			write(1, str, 1);
		str++;
	}
}
