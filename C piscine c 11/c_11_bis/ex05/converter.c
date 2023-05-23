/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:52:39 by lflandri          #+#    #+#             */
/*   Updated: 2022/08/01 14:51:08 by lflandri         ###   ########.fr       */
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

int	ft_atoi(char *str)
{
	int				sign;
	unsigned int	nb;

	nb = 0;
	sign = 1;
	while (*str == 32 || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	while (*str == 43 || *str == 45)
	{
		if (*(str++) == 45)
			sign = sign * -1;
	}
	while (*str > 47 && *str < 58)
	{
		nb = (nb * 10) + (*str - 48);
		str++;
	}
	return (sign * nb);
}
