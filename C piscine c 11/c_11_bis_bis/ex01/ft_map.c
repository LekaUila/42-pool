/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:29:32 by lflandri          #+#    #+#             */
/*   Updated: 2022/08/01 11:57:16 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*new_tab;
	int	ind;

	ind = -1;
	new_tab = malloc(sizeof(int) * length);
	while (++ind != length)
		new_tab[ind] = (*f)(tab[ind]);
	return (new_tab);
}
