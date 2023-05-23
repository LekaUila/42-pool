/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:24:01 by lflandri          #+#    #+#             */
/*   Updated: 2022/08/02 15:02:45 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	starting_crea_map(char *path)
{
	(void) path;
	
}

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

#include <stdio.h>

void read_standart_entry(void)
{
	char	str[1];
	char	*mal;
	int		size;
	
	mal = malloc(sizeof(char));
	*mal = '\0';
	size = 1;
	while (size == 1)
	{
		size = read(0, str, 1);
		if (*str == '\n')
			break;
		mal = add_to_malloc(mal, str);
	}
	starting_crea_map(mal);
	printf("%s",mal);
	free(mal);
}

int	main(int ac, char **av)
{
	int	ind;
	
	if (ac != 1)
	{
		ind = 0;
		while (++ind != ac)
			starting_crea_map(av[ind]);
	}
	else
		read_standart_entry();
	return (0);
}