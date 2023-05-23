/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:55:54 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/18 09:55:55 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*dest_tempo;

	dest_tempo = dest;
	while (*dest_tempo)
		dest_tempo++;
	while (*src && nb)
	{
		*dest_tempo = *src;
		src++;
		dest_tempo++;
		nb--;
	}
	*dest_tempo = 0;
	return (dest);
}
