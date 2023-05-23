/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standart_entry_reader.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 08:52:24 by lflandri          #+#    #+#             */
/*   Updated: 2022/08/03 18:08:16 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*add_to_malloc(char *mal, char *str)
{
	char	*new_mal;
	int		ind;

	ind = 0;
	while (mal[ind])
		ind++;
	new_mal = malloc(sizeof(char) * (ind + 2));
	ind = -1;
	while (mal[++ind])
		new_mal[ind] = mal[ind];
	new_mal[ind] = *str;
	new_mal[ind + 1] = 0;
	free(mal);
	return (new_mal);
}

void	read_map_on_entry(char *mal, unsigned int lines_counter)
{
	char				str[1];
	unsigned int		count;

	count = 0;
	if (!lines_counter)
	{
		free(mal);
		write(2, "map error\n", 10);
		return ;
	}
	mal = add_to_malloc(mal, "\n");
	while (count != lines_counter)
	{
		read(STDIN_FILENO, str, 1);
		if (*str == '\n')
			count++;
		mal = add_to_malloc(mal, str);
	}
	write(1, "\n", 1);
	starting_crea_map(NULL, mal);
}

void	check_read_map_on_entry(char *mal)
{
	char	*lines_counter;

	if (!(ft_strlen(mal) >= 4))
	{
		free(mal);
		write(2, "map error\n", 10);
		return ;
	}
	lines_counter = ft_strndup(mal, ft_strlen(mal) - 2);
	if (!ft_is_digit(lines_counter))
	{
		free(mal);
		free(lines_counter);
		write(2, "map error\n", 10);
		return ;
	}
	read_map_on_entry(mal, ft_atou(lines_counter));
	free(lines_counter);
}

void	read_standart_entry(void)
{
	char	str[1];
	char	*mal;
	int		size;
	int		fd;

	mal = malloc(sizeof(char));
	*mal = '\0';
	size = 1;
	while (size == 1)
	{
		size = read(STDIN_FILENO, str, 1);
		if (*str == '\n')
			break ;
		mal = add_to_malloc(mal, str);
	}
	fd = open(mal, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		starting_crea_map(mal, NULL);
		free(mal);
	}
	else
		check_read_map_on_entry(mal);
}
