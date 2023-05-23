/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:23:40 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/25 09:44:03 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	ind;

	if (min >= max)
		return (NULL);
	tab = malloc(sizeof(int) * (max - min));
	ind = 0;
	while (min < max)
	{
		tab[ind] = min++;
		ind++;
	}
	return (tab);
}
