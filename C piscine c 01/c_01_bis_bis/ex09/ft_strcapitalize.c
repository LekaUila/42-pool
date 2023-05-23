/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:43:11 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/16 12:43:12 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char *ft_strcapitalize(char *str)
{	
	char booll;
	int ind;

	boll=0;
	ind=-1;
	while (*(str + ++ind) != 0)
	{
		if (*(str + ++ind) > 64)
	}
}
