/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:55:54 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/19 10:40:28 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*dest_tempo;

	dest_tempo = dest;
	while (*dest_tempo)
		dest_tempo++;
	while (*src)
	{
		*dest_tempo = *src;
		src++;
		dest_tempo++;
	}
	*dest_tempo = 0;
	return (dest);
}
