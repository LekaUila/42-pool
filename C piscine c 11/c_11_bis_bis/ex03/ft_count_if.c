/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:16:08 by lflandri          #+#    #+#             */
/*   Updated: 2022/08/01 13:31:12 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	count;
	int	ind;

	count = 0;
	ind = -1;
	while (++ind != length)
		if (((*f)(tab[ind])))
			count++;
	return (count);
}
