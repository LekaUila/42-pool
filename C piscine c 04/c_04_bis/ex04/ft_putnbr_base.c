/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:54:39 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/19 14:54:43 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_base_is_correct(char *base)
{
	char	tab[255];
	int		lenbase;
	int		ind;

	tab[0] = 0;
	lenbase = 0;
	while (*base)
	{
		if (*base == 45 || *base == 43)
			return (0);
		ind = 0;
		while (ind != lenbase)
		{
			if (tab[ind] == *base)
				return (0);
			ind++;
		}
		tab[lenbase] = *base;
		lenbase++;
		base++;
	}
	if (lenbase < 2)
		return (0);
	return (lenbase);
}

void	ft_putnbr(long int nb, char *base, char lenbase)
{
	if (nb != 0)
	{
		ft_putnbr(nb / lenbase, base, lenbase);
		write(1, base + (nb % lenbase), 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			lenbase;
	long int	nb;

	nb = (long int) nbr;
	lenbase = ft_base_is_correct(base);
	if (lenbase)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			ft_putnbr(-nb, base, lenbase);
		}
		else if (nb == 0)
			write(1, base, 1);
		else
			ft_putnbr(nb, base, lenbase);
	}
}
