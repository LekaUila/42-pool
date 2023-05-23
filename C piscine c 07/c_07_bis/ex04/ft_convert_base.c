/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:52:56 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/26 17:17:23 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_base_is_correct(char *base);
int		in_base(char charr, char *base, int lenbase);
void	ft_atoi_base(char *str, char *base, long int *result);
int		puissance(int n, int p);

char	*ft_dec_to_base(long int nb, char *base, char lenbase, int count)
{
	char	*str;

	if (nb != 0)
	{
		str = ft_dec_to_base(nb / lenbase, base, lenbase, count + 1);
		str[count] = *(base + (nb % lenbase));
		return (str);
	}
	str = malloc(sizeof(char) * count);
	str[count] = 0;
	return (str);
}

void	ft_rev_int_tab(char *tab, int size)
{
	int	i;
	int	tempo;

	i = -1;
	while (++i != size / 2)
	{
		tempo = *(tab + i);
		*(tab + i) = *(tab + size - i - 1);
		*(tab + size - i - 1) = tempo;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != 0)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_convert_base_bis(long int nbr, char *base_to, int lenbase)
{
	char	*str;

	if (nbr < 0)
	{
		str = ft_dec_to_base(-nbr, base_to, lenbase, 1);
		*str = '-';
		ft_rev_int_tab(str + 1, ft_strlen(str + 1));
	}
	else if (!nbr)
	{
		str = malloc(sizeof(char) * 2);
		str[0] = *base_to;
		str[1] = 0;
	}
	else
	{
		str = ft_dec_to_base(nbr, base_to, lenbase, 0);
		ft_rev_int_tab(str, ft_strlen(str));
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	ft_atoi_base_result[2];
	int			lenbase;

	ft_atoi_base_result[0] = 0;
	ft_atoi_base_result[1] = 0;
	lenbase = ft_base_is_correct(base_to);
	ft_atoi_base(nbr, base_from, ft_atoi_base_result);
	if (!ft_atoi_base_result[1] || !lenbase)
		return (NULL);
	return (ft_convert_base_bis(ft_atoi_base_result[0], base_to, lenbase));
}
