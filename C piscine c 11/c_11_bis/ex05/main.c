/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:51:59 by lflandri          #+#    #+#             */
/*   Updated: 2022/08/01 17:30:25 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str);
void	add(int a, int b);
void	sous(int a, int b);
void	mult(int a, int b);
void	divi(int a, int b);
void	mod(int a, int b);

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	main(int ac, char **av)
{
	void	(*tab[5])(int, int);

	tab[0] = &add;
	tab[1] = &sous;
	tab[2] = &mult;
	tab[3] = &divi;
	tab[4] = &mod;
	if (ac == 4)
	{
		if (ft_strcmp("+", av[2]) == 0)
			tab[0](ft_atoi(av[1]), ft_atoi(av[3]));
		else if (ft_strcmp("-", av[2]) == 0)
			tab[1](ft_atoi(av[1]), ft_atoi(av[3]));
		else if (ft_strcmp("*", av[2]) == 0)
			tab[2](ft_atoi(av[1]), ft_atoi(av[3]));
		else if (ft_strcmp("/", av[2]) == 0)
			tab[3](ft_atoi(av[1]), ft_atoi(av[3]));
		else if (ft_strcmp("%", av[2]) == 0)
			tab[4](ft_atoi(av[1]), ft_atoi(av[3]));
		else
			write(1, "0\n", 2);
	}
	return (0);
}
