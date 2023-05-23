/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:53:10 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/25 17:40:15 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_base_is_correct(char *base)
{
	char	tab[255];
	int		lenbase;
	int		ind;

	tab[0] = 0;
	lenbase = 0;
	while (*base)
	{
		if (*base == 45 || *base == 43)
			return (0);
		ind = 0;
		while (ind != lenbase)
		{
			if (tab[ind] == *base)
				return (0);
			ind++;
		}
		tab[lenbase] = *base;
		lenbase++;
		base++;
	}
	if (lenbase < 2)
		return (0);
	return (lenbase);
}

int	in_base(char charr, char *base, int lenbase)
{
	while (lenbase-- != 0)
	{
		if (charr == *(base + lenbase))
			return (lenbase);
	}
	return (-1);
}

int	puissance(int n, int p)
{
	if (p != 0)
		return (n * puissance(n, p - 1));
	return (1);
}

int	ft_convert(char *str, int p, char *base, int lenbase)
{
	int	nb;

	if (p > -1)
	{
		nb = in_base(*(str), base, lenbase) * puissance(lenbase, p);
		return (nb + ft_convert(++str, p - 1, base, lenbase));
	}
	return (0);
}

void	ft_atoi_base(char *str, char *base, long int *result)
{
	int	lenbase;
	int	sign;
	int	p;

	lenbase = ft_base_is_correct(base);
	p = 0;
	if (lenbase)
	{
	result[1] = 1;
	sign = 1;
		while (*str == 32 || *str == '\f' || *str == '\n' || *str == '\r'
			|| *str == '\t' || *str == '\v')
			str++;
		while (*str == 43 || *str == 45)
		{
			if (*(str++) == 45)
				sign = sign * -1;
		}
		while (in_base(*(str + p), base, lenbase) != -1)
			p++;
		result[0] = (sign * ft_convert(str, --p, base, lenbase));
	}
}
