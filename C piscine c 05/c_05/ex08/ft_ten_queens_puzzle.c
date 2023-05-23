/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:43:07 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/21 14:43:08 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive(int tab[10][10], char *solution, int rang);

int	insert_d(int tab[10][10], char *solution, int rang, int ind)
{
	int	hauteur;
	int	rang_tempo;

	rang_tempo = rang + 1;
	hauteur = 1;
	tab[rang][ind] = 2;
	while (rang_tempo != 10)
	{
		tab[rang_tempo][ind] = 1;
		if (ind - hauteur >= 0)
			tab[rang_tempo][ind - hauteur] = 1;
		if (ind + hauteur < 10)
			tab[rang_tempo][ind + hauteur] = 1;
		rang_tempo++;
		hauteur++;
	}
	return (ft_recursive(tab, solution, rang + 1));
}

int	cptab(int tab[10][10], char *solution, int rang, int ind)
{
	int	x;
	int	y;
	int	tab_copy[10][10];

	x = 0;
	while (x != 10)
	{
		y = -1;
		while (++y != 10)
			tab_copy[x][y] = tab[x][y];
		x++;
	}
	return (insert_d(tab_copy, solution, rang, ind));
}

int	ft_recursive(int tab[10][10], char *solution, int rang)
{	
	int	ind;
	int	count;

	count = 0;
	ind = 0;
	if (rang == 10)
	{
		write(1, solution, 11);
		count++;
	}
	else
	{
		while (ind != 10)
		{
			if (!(tab[rang][ind]))
			{	
				*(solution + rang) = ind + 48;
				count += cptab(tab, solution, rang, ind);
			}
			ind++;
		}
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int		tab[10][10];
	char	solution[11];
	int		x;
	int		y;

	x = 0;
	while (x != 10)
	{
		y = -1;
		while (++y != 10)
			tab[x][y] = 0;
		x++;
	}
	solution[10] = '\n';
	return (ft_recursive(tab, solution, 0));
}
