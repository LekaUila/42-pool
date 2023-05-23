/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:44:57 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/15 13:44:59 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*dest_tempo;

	dest_tempo = dest;
	while (*src != 0)
	{
		*dest_tempo = *src;
		src++;
		dest_tempo++;
	}
	*dest_tempo = 0;
	return (dest);
}
