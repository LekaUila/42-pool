/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:23:40 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/26 16:23:50 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	ind;

	if (min >= max)
		*range = NULL;
	if (min >= max)
		return (0);
	*range = malloc(sizeof(int) * (max - min));
	ind = 0;
	while (min + ind < max)
	{
		(*range)[ind] = min + ind;
		ind++;
	}
	return (max - min);
}
