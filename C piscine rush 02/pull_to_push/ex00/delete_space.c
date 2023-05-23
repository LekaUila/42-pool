/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:36:22 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/31 12:44:48 by lflandri         ###   ########.fr       */
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
	*str = '\n';
	str++;
	size--;
	while (size)
	{
		*str = 0;
		str++;
		size--;
	}
	return (new_str);
}

int	next_after_space(char *str)
{
	while (*str && *str != '\n')
	{
		if (*str != ' ')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_del_space(char	*str, int size)
{
	char	*new_str;
	char	*tempo_str;
	char	boo[2];

	reset_boo(boo);
	new_str = malloc_reset(malloc(sizeof(char) * (size + 1)), size);
	tempo_str = ++new_str;
	while (*str)
	{
		if (*str != ' ' || (boo[1] && next_after_space(str)))
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
		if (*str == ' ')
			boo[1] = 0;
		str++;
	}
	return (new_str);
}
