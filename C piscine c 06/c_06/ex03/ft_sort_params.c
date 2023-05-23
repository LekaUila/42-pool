/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:12:36 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/21 21:12:38 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_swap(int *a, int *b)
{
	int	tempo;

	tempo = *a;
	*a = *b;
	*b = tempo;
}

void	ft_print(int ac, char **av, int *tab)
{
	char	*str;
	int		ind;

	ind = 0;
	while (ac != ind + 1)
	{
		str = av[tab[ind]];
		while (*str)
			write(1, str++, 1);
		write(1, "\n", 1);
		ind++;
	}
}

int	main(int ac, char **av)
{
	int		ind;
	int		ind2;
	int		tab[255];

	ind = -1;
	while (++ind != 255)
		tab[ind] = ind + 1;
	ind = ac - 1;
	while (ind)
	{
		ind2 = -1;
		while (++ind2 + 1 < ind)
		{
			if (ft_strcmp(av[tab[ind2]], av[tab[ind2 + 1]]) > 0)
				ft_swap(tab + ind2, tab + ind2 + 1);
		}
	ind--;
	}
	ft_print(ac, av, tab);
	return (0);
}
