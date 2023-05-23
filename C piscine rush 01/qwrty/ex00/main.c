/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:57:53 by maldavid          #+#    #+#             */
/*   Updated: 2022/07/23 19:07:48 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	ft_init_map();
	if (!ft_fill_map(av[1]))
		return (-1);
	return (0);
}
