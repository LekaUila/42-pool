/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:44:57 by lflandri          #+#    #+#             */
/*   Updated: 2022/09/27 11:05:02 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlcpy(char *dest, char *src, unsigned int n)
{
	char	*test;

	test = dest;
	while (n - 1 > 0 && *src != 0)
	{	
		*dest = *src;
		n--;
		src++;
		dest++;
	}
	if (n == 1)
	{
		*(dest) = 0;
	}
	return (test);
}
