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

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*dest_tempo;

	dest_tempo = dest;
	while (*src != 0 && n)
	{
		*dest_tempo = *src;
		src++;
		dest_tempo++;
		n--;
	}
	while (n)
	{
		*dest_tempo = 0;
		dest_tempo++;
		n--;
	}	
	return (dest);
}
