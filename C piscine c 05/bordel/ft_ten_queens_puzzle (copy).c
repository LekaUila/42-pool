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

void	print(int tab[10][10])
{
	int	x;
	int	y;

	x = 0;
	while (x != 10)
	{
		y = -1;
		while (++y != 10)
		{
			if (tab[x][y])
				write(1, "0", 1);
			else
				write(1, "1", 1);
		}
		write(1, "\n", 1);
		x++;
	}
}

/*
void	reboot_column(int *tab, int rang)
{
	int	ind;

	ind = -1;
	while (++ind != 10)
		tab[rang][ind] = 0;
}*/

void	cptab(int copy[10][10], int tab[10][10])
{
	int	x;
	int	y;

	x = 0;
	while (x != 10)
	{
		y = -1;
		while (++y != 10)
			copy[x][y] = tab[x][y];
		x++;
	}
}

void	insert_dame(int tab[10][10], int ind, int rang)
{
	int	hauteur;

	hauteur = 1;
	while (rang != 10)
	{
		tab[rang][ind] = 1;
		if (ind - hauteur >= 0 )
			tab[rang][ind - hauteur] = 1;
		if (ind + hauteur < 10 )
			tab[rang][ind + hauteur] = 1;
		rang++;
		hauteur++;
	}
}

void	ft_recursive(int tab[10][10], char *solution, int rang, int *count)
{	
	int	ind;
	int	tab_copy[10][10];

	write(1, solution, 11);
	ind = 0;
	if (rang == 1)
	{
		*count = *count + 1;
		write(1, solution, 11);
	}
	else
	{
		while (ind != 10)
		{
			if (!(tab[rang][ind]))
			{	
				cptab(tab_copy, tab);
				insert_dame(tab_copy, ind, rang);
				*(solution + rang) = ind + 48;
				print(tab);
				ft_recursive(tab_copy, solution, rang + 1, count);
			}
			ind++;
		}
	}
}



int ft_ten_queens_puzzle(void)
{
	int	tab[10][10];
	int	count;
	char	solution[11];

	count = 0;
	solution[10] = '\n';
	ft_recursive(tab, solution, 0, &count);
	return (count);
}

int main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}
