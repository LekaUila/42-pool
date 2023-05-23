/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoron <tmoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:16:20 by tmoron            #+#    #+#             */
/*   Updated: 2022/07/30 10:59:30 by tmoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_char_tab(char *tab, int size)
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
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(to_find);
	if (to_find[0] == '\0')
		return (str);
	while (str[0])
	{
		while (i < len)
		{
			if (str[i] != to_find[i])
				break ;
			i++;
		}
		if (i == len)
			return (str);
		i = 0;
		str++;
	}
	return ((0));
}

void ft_put_nbr(char *nbr, char *dict)
{
	int len;

	
}

int main(void)
{
	ft_put_nbr("10000","")
}