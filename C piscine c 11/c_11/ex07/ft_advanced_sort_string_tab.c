/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:05:20 by lflandri          #+#    #+#             */
/*   Updated: 2022/08/01 15:49:19 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_pointer(char **a, char **b)
{
	char	*tempo;

	tempo = *a;
	*a = *b;
	*b = tempo;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	ind;
	int	pind;

	pind = -1;
	while (tab[++pind] != 0)
	{
		ind = -1;
		while (tab[++ind + 1] != 0)
		{	
			if ((*cmp)(tab[ind], tab[ind + 1]) > 0)
				ft_swap_pointer(tab + ind, tab + ind + 1);
		}	
	}
}
