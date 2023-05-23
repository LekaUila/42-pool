/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchedota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:18:02 by mchedota          #+#    #+#             */
/*   Updated: 2022/07/16 10:51:16 by tmoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	trop_de_lignes(int flag_x, int x, int flag_y, int y)
{
	int	test_x;

	test_x = flag_x == 1 || flag_x == x;
	if (flag_x == 1 && flag_y == 1)
		ft_putchar('/');
	else if (flag_x == x && flag_y == 1)
		ft_putchar('\\');
	else if (flag_x == 1 && flag_y == y)
		ft_putchar('\\');
	else if (flag_x == x && flag_y == y)
		ft_putchar('/');
	else if (test_x || (flag_y == 1 || flag_y == y))
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	flag_x;
	int	flag_y;

	flag_y = 0;
	while (y >= ++flag_y)
	{
		flag_x = 0;
		while (x >= ++flag_x)
		{
			trop_de_lignes(flag_x, x, flag_y, y);
		}
		ft_putchar('\n');
	}
}
