/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvet <cchauvet@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:55:35 by cchauvet          #+#    #+#             */
/*   Updated: 2022/08/02 11:16:56 by cchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_filelen(char *path)
{
	int		file_descriptor;
	int		letter_readed_counter;
	char	letters_readed[10];
	int		length;

	file_descriptor = open(path, O_RDONLY);
	if (file_descriptor == -1)
		return (-1);
	length = 0;
	letter_readed_counter = -1;
	while (letter_readed_counter != 0)
	{
		letter_readed_counter = read(file_descriptor, letters_readed, 10);
		length = length + letter_readed_counter;
	}
	if (close(file_descriptor) == -1)
		return (-1);
	return (length);
}

char	*ft_filereader(char *path)
{
	char	*str;
	int		file_descriptor;
	int		length;

	length = ft_filelen(path);
	if (length < 1)
	{
		str = malloc(sizeof(*str));
		str[0] = 0;
		return (str);
	}
	str = malloc(sizeof(*str) * (length + 1));
	file_reader = open(path, O_RDONLY);
	if (file_reader == -1)
	{
		str[0] = 0;
		return (str);
	}
	read(file_descriptor, str, length);
	str[length - 1] = 0;
	if (close(file_descriptor) == -1)
		str[0] = 0;
	return (str);
}
