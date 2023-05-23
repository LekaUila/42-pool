/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlauvray <nlauvray@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:35:51 by nlauvray          #+#    #+#             */
/*   Updated: 2022/07/31 12:37:19 by cchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (str[i] != 0)
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == 0)
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
