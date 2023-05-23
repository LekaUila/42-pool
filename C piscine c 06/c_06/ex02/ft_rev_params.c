/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:12:36 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/21 21:12:38 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	char	*str;

	while (ac != 1)
	{
		str = av[ac - 1];
		while (*str)
			write(1, str++, 1);
		write(1, "\n", 1);
		ac--;
	}
	return (0);
}
