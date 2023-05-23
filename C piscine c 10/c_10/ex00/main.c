/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:25:15 by lflandri          #+#    #+#             */
/*   Updated: 2022/08/01 09:01:36 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	reader(int fd)
{
	char	tab[100];
	int		size;

	size = 100;
	while (size == 100)
	{
		size = read(fd, tab, 100);
		if (size == -1)
		{
			write(2, "Cannot read file.\n", 18);
			return (3);
		}
		write(1, tab, size);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	fd;

	if (ac < 2)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	else if (ac > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (2);
	}	
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (3);
	}
	return (reader(fd));
}
