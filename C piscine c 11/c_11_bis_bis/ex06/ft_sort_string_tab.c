/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:05:20 by lflandri          #+#    #+#             */
/*   Updated: 2022/08/01 15:43:39 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_pointer(char **a, char **b)
{
	char	*tempo;

	tempo = *a;
	*a = *b;
	*b = tempo;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_sort_string_tab(char **tab)
{
	int	ind;
	int	pind;

	pind = -1;
	while (tab[++pind] != 0)
	{
		ind = -1;
		while (tab[++ind + 1] != 0)
		{	
			if (ft_strcmp(tab[ind], tab[ind + 1]) > 0)
				ft_swap_pointer(tab + ind, tab + ind + 1);
		}	
	}
}
