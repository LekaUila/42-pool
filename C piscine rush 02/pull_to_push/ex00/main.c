/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 09:36:19 by nlocusso          #+#    #+#             */
/*   Updated: 2022/07/31 17:07:44 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*dict_to_str(char	*dict);
int		full_z(char *nbr);
void	ft_putnbr(char *str, char *del_space);
char	*ft_rev_char_tab(char *tab, int size);
int		ft_strlen(char *str);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strchar(char *str, char to_find);
void	ft_recursive_printer(char *dic, char *nbr_r, int i, char *del_space);

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char	*nbr_without_start_0(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '+')
		i++;
	while (nbr[i] == '0' && nbr[i + 1])
		i++;
	return (nbr + i);
}

/*
 If you want to change mode to be able to write more number, replace 
(ft_strcmp(nbr_without_start_0(argv[argc - 1]), "4294967295") > 0
			&& ft_strlen(argv[argc - 1]) == 10)
		|| ft_strlen(argv[argc - 1]) > 10
with   ft_strlen(nbr_without_start_0(argv[argc - 1])) > 37
*/

int	ft_parsing(int argc, char *argv[])
{
	int	i;

	i = 0;
	if ((argc != 2 && argc != 3)
		|| (ft_strcmp(nbr_without_start_0(argv[argc - 1]), "4294967295") > 0
			&& ft_strlen(argv[argc - 1]) == 10)
		|| ft_strlen(argv[argc - 1]) > 10)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (argv[argc - 1][0] == '+')
		i++;
	while (argv[argc - 1][i] != '\0')
	{
		if (argv[argc - 1][i] < '0' || argv[argc - 1][i] > '9')
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

int	starting_recursive(char *dict, char *nbr)
{
	char	del_space;
	char	*rev_nbr;

	del_space = 0;
	if (full_z(nbr) == 1)
	{
		ft_putnbr(ft_strstr(dict, "0"), &del_space);
		write(1, "\n", 1);
		return (0);
	}
	nbr = nbr_without_start_0(nbr);
	if (ft_strlen(nbr) == 1)
		ft_putnbr(ft_strchar(dict, *nbr), &del_space);
	rev_nbr = ft_rev_char_tab(nbr, ft_strlen(nbr));
	ft_recursive_printer(dict, rev_nbr, 0, &del_space);
	write(1, "\n", 1);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*dict;
	char	*nbr;

	if (ft_parsing(argc, argv))
		return (1);
	if (argc == 3)
	{
		dict = argv[1];
		nbr = argv[2];
	}
	else
	{
		dict = "numbers.dict";
		nbr = argv[1];
	}
	dict = dict_to_str(dict);
	if (!(*dict))
		return (1);
	return (starting_recursive(dict, nbr));
}
