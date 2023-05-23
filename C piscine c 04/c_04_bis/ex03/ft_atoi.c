/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:09:36 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/19 10:09:38 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int				sign;
	unsigned int	nb;

	nb = 0;
	sign = 1;
	while (*str == 32 || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	while (*str == 43 || *str == 45)
	{
		if (*(str++) == 45)
			sign = sign * -1;
	}
	while (*str > 47 && *str < 58)
	{
		nb = (nb * 10) + (*str - 48);
		str++;
	}
	return (sign * nb);
}
