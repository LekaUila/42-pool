/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:16:20 by tmoron            #+#    #+#             */
/*   Updated: 2022/07/31 17:48:02 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr(char *str, char *del_space);
char	*ft_rev_char_tab(char *tab, int size);
int		ft_strlen(char *str);
char	*ft_strstr(char *str, char *to_find, char free);
char	*ft_strchar(char *str, char to_find);
char	*ft_add0(int z_nbr, char nbr);

int	full_z(char *nbr)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(nbr))
		if (nbr[i] != '0')
			return (0);
	return (1);
}

void	print_01_to_99(char *nbr, char *dic, char *del_space)
{
	char	temp[2];

	if (nbr[1] < '1' && (nbr[0] != '0' || nbr[1] != 1))
	{
		if (nbr[0] != '0')
			ft_putnbr(ft_strchar(dic, nbr[0]), del_space);
	}
	else if (nbr[1] >= '2')
	{
		ft_putnbr(ft_strstr(dic, ft_add0(1, nbr[1]), 1), del_space);
		if (nbr[0] != '0')
		{
			ft_putnbr(ft_strchar(dic, nbr[0]), del_space);
		}
	}
	else
	{
		if (nbr[1] != '0')
		{
			temp[0] = nbr[1];
			temp[1] = nbr[0];
			ft_putnbr(ft_strstr(dic, temp, 0), del_space);
		}
	}
}

void	ft_recursive_if(char *dic, char *nbr_r, int i, char *del_space)
{
	if (i % 3 == 2)
	{
		if (nbr_r[i] != '0')
		{
			ft_putnbr(ft_strchar(dic, nbr_r[i]), del_space);
			ft_putnbr(ft_strstr(dic, ft_add0(2, '1'), 1), del_space);
		}
	}
	if (i % 3 == 1)
	{
		print_01_to_99(nbr_r + i - 1, dic, del_space);
	}
}

void	ft_recursive_else(char *dic, char *nbr_r, int i, char *del_space)
{
	if (nbr_r[i] != '0' || nbr_r[i + 1] != '0'
		|| nbr_r[i + 2] != '0')
	{
		if (i == ft_strlen(nbr_r) - 1)
		{
			ft_putnbr(ft_strchar(dic, nbr_r[i]), del_space);
		}
		if (i != 0)
			ft_putnbr(ft_strstr(dic, ft_add0(i, '1'), 1), del_space);
	}
}

void	ft_recursive_printer(char *dic, char *nbr_r, int i, char *del_space)
{
	if (nbr_r[i] && i != 39)
	{
		ft_recursive_printer(dic, nbr_r, i + 1, del_space);
		if (i == 0)
			return ;
		else
		{
			if (!(i % 3 == 0))
			{
				ft_recursive_if(dic, nbr_r, i, del_space);
			}
			else
			{
				ft_recursive_else(dic, nbr_r, i, del_space);
			}
		}
	}
}
