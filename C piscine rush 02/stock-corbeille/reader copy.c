/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 09:47:06 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/30 11:57:41 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


#include <stdio.h>

char	*ft_read_dict(char *dict)
{
	int		fd;
	int		size_read;
	int 	size_malloc;
	char	*str;
	char	*tempo;
	char	*save_str;

	size_malloc = 0;
	size_read = 1;
	fd = open(dict, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	while (size_read >= size_malloc - 1)
	{
		size_malloc +=100;
		str = malloc(sizeof(char) * size_malloc);
		tempo = read(fd, str, size_malloc - 1);
		if (size_read == -1)
		{
			write(1, "Dict Error\n", 11);
			return (0);
		}
		free(str);
		//printf("\n%d et %d\n",size_read, size_malloc - 1);
		write(1, str, size_read);
	}
	str = malloc(sizeof(char) * size_malloc);
	size_read = read(fd, str, size_malloc);
	
	str[size_read] = 0;
	return (str);
}

int main(void)
{
	ft_read_dict("fichier_a_lire");
	ft_read_dict("coucou.txt");
	//printf("%ls\n",ft_read_dict("coucou.txt"));
	ft_read_dict("coucou2.txt");
	ft_read_dict("dict");
	//printf("%ls\n",ft_read_dict("dict"));
}