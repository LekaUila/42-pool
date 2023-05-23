/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
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
	int		ind;

	ind = 0;
	while (ac != ind + 1)
	{
		str = av[1 + ind];
		while (*str)
			write(1, str++, 1);
		write(1, "\n", 1);
		ind++;
	}
	return (0);
}
