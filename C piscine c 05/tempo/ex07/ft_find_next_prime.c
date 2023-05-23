/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:46:05 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/21 14:42:31 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_bis(int nb, int max, int min)
{
	int	middle;

	if (min + 1 == max)
		return (min);
	middle = (max - min) / 2 + min;
	if (middle * middle == nb)
		return (middle);
	else if (middle * middle > nb)
		return (ft_sqrt_bis(nb, middle, min));
	else
		return (ft_sqrt_bis(nb, max, middle));
}

int	ft_sqrt(int nb)
{	
	if (nb < 0)
		return (0);
	return (ft_sqrt_bis(nb, nb, 0));
}

int	ft_is_prime(int nb)
{
	int	racine;

	if (!(nb % 2) && nb != 2)
		return (0);
	racine = ft_sqrt(nb);
	if (racine == 1)
		return (1);
	if (!(nb % racine))
		return (0);
	if (!(racine % 2))
		racine--;
	while (racine != 1)
	{
		if (!(nb % racine))
			return (0);
		racine -= 2 ;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (!(nb % 2))
		nb++;
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb += 2;
	}
}
