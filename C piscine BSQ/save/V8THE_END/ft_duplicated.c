/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicated.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvet <cchauvet@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:50:50 by cchauvet          #+#    #+#             */
/*   Updated: 2022/08/03 12:38:01 by cchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_duplicated(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i + 1] != 0)
	{
		j = i + 1;
		while (str[i] != str[j])
		{
			if (str[j] == 0)
				break ;
			j++;
		}
		if (str[j] != 0)
			return (1);
		i++;
	}
	return (0);
}
