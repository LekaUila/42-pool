/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 09:47:06 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/31 19:08:13 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

char	*ft_del_space(char	*str, int size);
int		check_dict(char *str);
int		check_key(char *str);

int	ft_check_error(int nb)
{
	if (nb == -1)
		return (1);
	return (0);
}

char	*ft_read(char *dict, int size_read, int size_malloc)
{
	int		fd;
	char	*str;

	fd = open(dict, O_RDONLY);
	str = malloc(sizeof(char) * size_malloc);
	read(fd, str, size_malloc);
	close(fd);
	str[size_malloc - 100 + size_read] = 0;
	return (str);
}

char	*ft_read_dict(char *dict)
{
	int		fd;
	int		size_read;
	int		size_malloc;
	char	str[100];

	size_malloc = 0;
	size_read = 100;
	fd = open(dict, O_RDONLY);
	if (ft_check_error(fd))
		return ("a");
	while (size_read == 100)
	{
		size_malloc += 100;
		size_read = read(fd, str, 100);
		if (ft_check_error(size_read))
			return ("a");
	}
	close(fd);
	return (ft_read(dict, size_read, size_malloc));
}

char	*dict_to_str(char	*dict)
{
	char	*str;
	char	*str_bis;
	int		i;

	str = ft_read_dict(dict);
	if (*str == 'a' || check_dict(str))
	{
		write(1, "Dict Error\n", 11);
		return ("");
	}
	str_bis = str;
	i = 0;
	while (str_bis[i] != 0)
		i++;
	i++;
	str_bis = ft_del_space(str, i);
	if (!(check_key(str_bis)))
	{
		free(str_bis);
		write(1, "Dict Error\n", 11);
		return ("");
	}
	free(str);
	return (str_bis);
}
