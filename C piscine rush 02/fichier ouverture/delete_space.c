/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:36:22 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/30 15:12:35 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	reset_boo(char boo[2])
{
	boo[0] = 0;
	boo[1] = 0;
}

char	*malloc_reset(char *str, int size)
{
	char	*new_str;

	new_str = str;
	while (size)
	{
		str = 0;
		str++;
		size--;
	}
	return (new_str);
}

char	*ft_del_space(char	*str, int size)
{
	char	*new_str;
	char	*tempo_str;
	char	boo[2];

	reset_boo(boo);
	new_str = malloc_reset(malloc(sizeof(char) * size), size);
	tempo_str = new_str;
	while (*str)
	{
		if (*str != ' ' || boo[1])
		{
			*tempo_str = *str;
			tempo_str++;
		}
		if (*str != ' ' && boo[0])
			boo[1] = 1;
		if (*str == ':')
			boo[0] = 1;
		if (*str == '\n')
			reset_boo(boo);
		str++;
	}
	return (new_str);
}
