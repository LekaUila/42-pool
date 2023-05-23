/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:36:10 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/14 08:59:15 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_detecte(int nb)
{
	int	num;

	num = 1;
	while (nb != 0)
	{
		num = num * 10;
		nb = nb / 10;
	}
	return (num / 10);
}

int	ft_puissance_10(int nb)
{
	int	v;

	v = 10;
	while (--nb != 0)
	{
		v = v * 10;
	}
	return (v);
}

void	ft_putnbr(int nb)
{
	int	divi;
	int	print;

	divi = ft_detecte(nb);
	while (divi != 0)
	{
		print = nb / divi + 48;
		write(1, &print, 1);
		nb = nb % divi;
		divi = divi / 10;
	}
}

int	ft_test(int nb)
{
	if (nb < 10)
		return (1);
	if (nb % 10 > (nb % 100) / 10 )
		return (ft_test(nb / 10));
	else
		return (0);
}

void	ft_print_combn(int n)
{
	int	nb;
	int	boo;
	int	p;

	p = ft_puissance_10(n);
	boo = 0;
	nb = 0;
	while (nb++ != p - (p / 10 * (n - 1)))
	{
		if (ft_test(nb) && nb > (p / 100) - 1 )
		{
			if (boo)
				write(1, ", ", 2);
			else
				boo = 1;
			if (nb < (p / 10) + 1)
			{
				write(1, "0", 1);
				if (n == 1)
					write(1, ", ", 2);
				boo = 1;
			}
			ft_putnbr(nb);
		}
	}	
}
