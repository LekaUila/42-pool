/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:12:47 by lflandri          #+#    #+#             */
/*   Updated: 2022/08/01 17:30:00 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

void	add(int a, int b)
{
	ft_putnbr(a + b);
	write(1, "\n", 1);
}

void	sous(int a, int b)
{
	ft_putnbr(a - b);
	write(1, "\n", 1);
}

void	mult(int a, int b)
{
	ft_putnbr(a * b);
	write(1, "\n", 1);
}

void	divi(int a, int b)
{
	if (b != 0)
	{
		ft_putnbr(a / b);
		write(1, "\n", 1);
	}
	else
		write(1, "Stop : division by zero\n", 24);
}

void	mod(int a, int b)
{
	if (b != 0)
	{
		ft_putnbr(a % b);
		write(1, "\n", 1);
	}
	else
		write(1, "Stop : modulo by zero\n", 22);
}
