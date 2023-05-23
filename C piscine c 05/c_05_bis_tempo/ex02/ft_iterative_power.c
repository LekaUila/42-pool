/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:25:45 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/20 13:25:46 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	stock;

	stock = 1;
	if (power < 0)
		return (0);
	while (power--)
		stock = stock * nb;
	return (stock);
}
