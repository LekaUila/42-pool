/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contain_only.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:44:05 by cchauvet          #+#    #+#             */
/*   Updated: 2022/08/03 11:05:35 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_contain_only(char **lines, char *charset)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	while (lines[k][0] != 0)
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
