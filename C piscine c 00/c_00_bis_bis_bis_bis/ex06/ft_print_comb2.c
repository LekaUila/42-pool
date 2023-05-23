/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:36:10 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/13 19:55:17 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_tempo(char n1, char n2, char n3, char n4)
{
	n1 = n1 + 48;
	n2 = n2 + 48;
	n3 = n3 + 48;
	n4 = n4 + 48;
	write(1, &n1, 1);
	write(1, &n2, 1);
	write(1, " ", 1);
	write(1, &n3, 1);
	write(1, &n4, 1);
	if (!(n1 == 57 && n2 == 56))
		write(1, ", ", 1);
}

void	ft_print_comb2(void)
{
	char	nb1;
	char	nb2;

	nb1 = -1;
	nb2 = 0;
	while (++nb1 != 99)
	{
		while (++nb2 != 100)
			ft_tempo(nb1 / 10, nb1 % 10, nb2 / 10, nb2 % 10);
		nb2 = nb1 + 1;
	}
}
