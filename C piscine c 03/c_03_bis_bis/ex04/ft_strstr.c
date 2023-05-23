/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:55:54 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/19 10:43:47 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*str_tempo;
	char	*to_find_tempo;

	while (*str)
	{
		str_tempo = str;
		to_find_tempo = to_find;
		while (*str_tempo && *str_tempo++ == *to_find_tempo++)
		{
			if (!(*to_find_tempo))
				return (str);
		}
		str++;
	}
	return (0);
}
