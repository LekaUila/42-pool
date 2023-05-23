/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:47:59 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/14 19:48:01 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	tempo;

	tempo = *a;
	*a = *b;
	*b = tempo;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	ind;
	int	pind;

	pind = -1;
	while (++pind - 1 != size)
	{
		ind = -1;
		while (++ind + 1 < size)
		{	
			if (tab[ind] > tab[ind + 1])
				ft_swap(tab + ind, tab + ind + 1);
		}	
	}
}
