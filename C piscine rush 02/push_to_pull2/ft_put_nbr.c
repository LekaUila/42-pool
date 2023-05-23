/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:16:20 by tmoron            #+#    #+#             */
/*   Updated: 2022/07/31 10:38:29 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putnbr(char *str)
{
    while (*str != ':')
        str++;
    str++;
    while (*str == ' ')
        str++;
    while (*str != '\n')
        write(1, str++, 1);
	write(1, " ", 1);
}

char	*ft_rev_char_tab(char *tab, int size)
{
	int	i;
	char	temp;

	i = size;
	while (i != size / 2)
	{
		temp = tab[size - i];
		tab[size - i] = tab[i - 1];
		tab[i - 1] = temp;
		i--;
	}
	return (tab);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

char    *ft_strstr(char *str, char *to_find)
{
        int     i;
        int     verif;

        if (*to_find == '\0')
                return (str);
        while (*str)
        {
                if (*str == *to_find)
                {
                        i = 0;
                        verif = 0;
                        while (*(to_find + i))
                        {
                                if (*(to_find + i) != *(str + i))
                                        verif = 1;
                                i++;
                        }
                        if (verif == 0)
                                return (str);
                }
                str++;
        }
        return (0);
}

char    *ft_strchar (char *str, char to_find)
{
        while (*str)
        {
                if (*str == to_find)
                                return (str);
                str++;
        }
        return (0);
}

/*
void ft_put_nbr(char *nbr, char *dict)
{
	int len;
}
*/

char	*ft_add0(int z_nbr, char nbr)
{
	char	*str;
	int		y;

	y = 0;
	str = malloc(sizeof(char) * z_nbr + 2);
	str[0] = nbr;
	while (++y < z_nbr + 1)
		str[y] = '0';
	str[y] = '\0';
	return (str);
}

int		full_z(char *nbr)
{
	int		i;

	i = -1;
	while (++i < ft_strlen(nbr))
		if (nbr[i] != '0')
			return (0);
	return (1);
}

void	print_01_to_99(char *nbr, char *dic)
{
	char	temp[2];
	
	if (nbr[1] < '1' && (nbr[0] != '0' || nbr[1] != 1))
	{
			if (nbr[0] != '0')
				ft_putnbr(ft_strchar(dic, nbr[0]));
	}
	else if (nbr[1] >= '2')
	{
		ft_putnbr(ft_strstr(dic, ft_add0(1, nbr[1])));
		if (nbr[0] != '0')
		{
			ft_putnbr(ft_strchar(dic, nbr[0]));
		}
	}
	else
	{
		if (nbr[1] != '0')
		{
			temp[0] = nbr[1];
			temp[1] = nbr[0];
			ft_putnbr(ft_strstr(dic, temp));
		}
	}

}

void	ft_recursive_printer (char *dic, char* nbr_r, int i)
{
	char	c;

	if (nbr_r[i] && i != 39)
	{
		c = nbr_r[i];
		ft_recursive_printer(dic, nbr_r, i+1);
		if (i == 0)
			return ;
		else
		{
			if (!(i % 3 == 0))
			{
				if (i % 3 == 2)
				{
					if (nbr_r[i] != '0')
					{
						ft_putnbr(ft_strchar(dic, c));
						ft_putnbr(ft_strstr(dic, ft_add0(2, '1')));
					}
				}
				if (i % 3 == 1)
				{
					print_01_to_99(nbr_r + i - 1, dic);
				}
			}
			else
			{
				if (nbr_r[i] != '0' || nbr_r[i + 1] != '0'
					|| nbr_r[i + 2] != '0')
				{
					if (i == ft_strlen(nbr_r) - 1)
					{
						ft_putnbr(ft_strchar(dic, c));
					}
					if (i != 0)
						ft_putnbr(ft_strstr(dic, ft_add0(i, '1')));
				}
			}
		}
	}
}

int main(void)
{
	char	nbr[] = "00000000000000999999999999999999999999999999999999999";
	int		i;
	char	*string = "0: zero\n1: one\n2: two\n3: three\n4: four\n5: five\n6: six\n7: seven\n8: eight\n9: nine\n10: ten\n11: eleven\n12: twelve\n13: thirteen\n14: fourteen\n15: fifteen\n16: sixteen\n17: seventeen\n18: eighteen\n19: nineteen\n20: twenty\n30: thirty\n40: forty\n50: fifty\n60: sixty\n70: seventy\n80: eighty\n90: ninety\n100: hundred\n1000: thousand\n1000000: million\n1000000000: billion\n1000000000000: trillion\n1000000000000000: quadrillion\n1000000000000000000: quintillion\n1000000000000000000000: sextillion\n1000000000000000000000000: septillion\n1000000000000000000000000000: octillion\n1000000000000000000000000000000: nonillion\n1000000000000000000000000000000000: decillion\n1000000000000000000000000000000000000: undecillion\n";
	
	if (full_z(nbr) == 1)
	{
		ft_putnbr(ft_strstr(string, "0"));
		return (0);
	}
	i = 0;
	while (nbr[i] == '0')
		i++;
	ft_recursive_printer(string, ft_rev_char_tab(nbr + i - 1,
	 ft_strlen(nbr + i - 1)), 0);
}