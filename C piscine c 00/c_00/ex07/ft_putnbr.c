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
