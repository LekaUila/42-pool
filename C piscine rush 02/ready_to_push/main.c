/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 09:36:19 by nlocusso          #+#    #+#             */
/*   Updated: 2022/07/30 18:40:50 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*dict_to_str(char	*dict);

int	ft_parsing(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	while (argv[argc - 1][i] != '\0')
	{
		if (argv[argc - 1][i] < '0' || argv[1][i] > '9')
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

//#include <stdio.h>
int	main(int argc, char *argv[])
{
	char	*dict;

	if (ft_parsing(argc, argv))
		return (1);
	if (argc == 3)
		dict = argv[1];
	else
		dict = "numbers.dict";
	//printf("%s", dict_to_str(dict));
	return (0);
}
