/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:43:31 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/27 19:06:19 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_bis(int n)
{
	if (n != 0)
	{
		ft_putnbr_bis(n / 10);
		n = (n % 10) + 48;
		write(1, &n, 1);
	}
}

void	ft_put_nbr(int n)
{
	if (n == 0)
		write(1, "0", 1);
	else
		ft_putnbr_bis(n);
}

void	ft_putstr(char *str)
{
	while (*str != 0)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (((*par).str))
	{
		ft_put_nbr((*par).size);
		write(1, "\n", 1);
		ft_putstr((*par).str);
		write(1, "\n", 1);
		ft_putstr((*par).copy);
		write(1, "\n", 1);
		par++;
	}
}
