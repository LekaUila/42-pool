/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvet <cchauvet@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:19:17 by cchauvet          #+#    #+#             */
/*   Updated: 2022/08/02 10:25:52 by cchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strndup(char *src, unsigned int n)
{
	char	*dest;
	int		i;

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
