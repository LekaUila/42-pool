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
	int	diff;

	nb = 0;
	while (nb++ != ft_puissance_10(n))
	{
		diff = (ft_puissance_10(n) / ft_detecte(nb)) / 100;
		if (ft_test(nb))
		{
			if (nb != 1)
				write(1, ", ", 1);
			while (diff != 0)
			{
				write(1, "0", 1);
				diff = diff / 10;
			}
			ft_putnbr(nb);
		}
	}	
}
