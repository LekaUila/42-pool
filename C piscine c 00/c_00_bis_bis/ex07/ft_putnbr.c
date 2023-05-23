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
	long int	num;

	num = 1;
	while (nb != 0)
	{
		num = num * 10;
		nb = nb / 10;
	}
	return (num / 10);
}

void	ft_putnbr_bis(int nb)
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

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr_bis(-1 * nb);
	}
	else if (nb == 0)
		write(1, "0", 1);
	else
		ft_putnbr_bis(nb);
}
