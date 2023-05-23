/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contain_only.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvet <cchauvet@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:44:05 by cchauvet          #+#    #+#             */
/*   Updated: 2022/08/02 12:12:39 by cchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_contain_only(char **lines, char *charset)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	while (lines[k] != 0)
	{
		i = 0;
		while (lines[k][i] != 0)
		{
			j = 0;
			while (charset[j] != lines[k][i] && charset[j] != 0)
				j++;
			if (charset[j] == 0)
				return (0);
			i++;
		}
		k++;
	}
	return (1);
}
