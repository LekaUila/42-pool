/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:03:04 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/20 19:03:05 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_bis(long int nb, int max, int min)
{
	long int	middle;

	middle = (max - min) / 2 + min;
	if (middle * middle == nb)
		return (middle);
	else if (min + 1 == max)
		return (0);
	else if (middle * middle > nb)
		return (ft_sqrt_bis(nb, middle, min));
	else
		return (ft_sqrt_bis(nb, max, middle));
}

int	ft_sqrt(int nb)
{	
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	return (ft_sqrt_bis(nb, nb, 0));
}
