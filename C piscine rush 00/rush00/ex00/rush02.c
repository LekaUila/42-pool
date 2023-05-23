/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchedota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:18:02 by mchedota          #+#    #+#             */
/*   Updated: 2022/07/16 10:02:11 by mchedota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	flag_x;
	int	flag_y;
	int	test_x;

	flag_y = 1;
	while (y >= flag_y)
	{
		flag_x = 1;
		while (x >= flag_x)
		{
			test_x = flag_x == 1 || flag_x == x;
			if (test_x && flag_y == 1)
				ft_putchar('A');
			else if (test_x && flag_y == y)
				ft_putchar('C');
			else if (test_x || (flag_y == 1 || flag_y == y))
				ft_putchar('B');
			else
				ft_putchar(' ');
			flag_x++;
		}
		ft_putchar('\n');
		flag_y++;
	}
}
