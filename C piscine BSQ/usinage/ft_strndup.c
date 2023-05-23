/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:19:17 by cchauvet          #+#    #+#             */
/*   Updated: 2022/08/02 14:24:27 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strndup(char *src, unsigned int n)
{
	char				*dest;
	unsigned int		i;

	dest = malloc(sizeof(*src) * (ft_strlen(src) + 1));
	i = 0;
	while (src[i] != 0 && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
