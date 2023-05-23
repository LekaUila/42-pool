/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:55:54 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/19 10:48:25 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int nb)
{
	char			*dest_tempo;
	unsigned int	i;	

	i = 0;
	dest_tempo = dest;
	while (*dest_tempo++)
		i++;
	while (*src && nb - 1)
	{
		*dest_tempo = *src;
		src++;
		dest_tempo++;
		nb--;
		i++;
	}
	dest_tempo = 0;
	return (i);
}
