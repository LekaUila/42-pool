/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:30:38 by lflandri          #+#    #+#             */
/*   Updated: 2022/08/01 19:11:51 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	ind;

	ind = -1;
	if (!(length))
		return (1);
	if (tab[0] <= tab[length - 1])
	{
		while (++ind +1 != length)
			if ((*f)(tab[ind + 1], tab[ind]) < 0)
				return (0);
	}
	else
		while (++ind +1 != length)
			if ((*f)(tab[ind + 1], tab[ind]) > 0)
				return (0);
	return (1);
}
