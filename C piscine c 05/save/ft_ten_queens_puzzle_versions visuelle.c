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

void	ft_recursive(int tab[10][10], char *solution, int rang, int *count);

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
			if (tab[y][x]==1)
				write(1, "1", 1);
			else if (tab[y][x]==2)
				write(1, "2", 1);
			else
				write(1, "0", 1);
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

void	insert_dame(int tab[10][10], char *solution, int rang, int *count, int ind)
{
	int	hauteur;
	int	rang_tempo;

	rang_tempo = rang + 1;
	hauteur = 1;
	tab[rang][ind] = 2;
	while (rang_tempo != 10)
	{
		//write(1, "test\n", 5);
		tab[rang_tempo][ind] = 1;
		if (ind - hauteur >= 0 )
			tab[rang_tempo][ind - hauteur] = 1;
		if (ind + hauteur < 10 )
			tab[rang_tempo][ind + hauteur] = 1;
		rang_tempo++;
		hauteur++;
	}
	//print(tab);
	ft_recursive(tab, solution, rang + 1, count);
}

void	cptab(int tab[10][10], char *solution, int rang, int *count, int ind)
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
	insert_dame(tab_copy, solution, rang, count, ind);
}

void	ft_recursive(int tab[10][10], char *solution, int rang, int *count)
{	
	int	ind;
	ind = 0;
	if (rang == 10)
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
				*(solution + rang) = ind + 48;
				//write(1, solution, 11);
				cptab(tab, solution, rang, count, ind);
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
	int	x;
	int	y;

	x = 0;
	while (x != 10)
	{
		y = -1;
		while (++y != 10)
			tab[x][y] = 0;
		x++;
	}
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
