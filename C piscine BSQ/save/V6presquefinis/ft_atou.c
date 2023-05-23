/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvet <cchauvet@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:37:25 by cchauvet          #+#    #+#             */
/*   Updated: 2022/08/02 10:37:52 by cchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_atou(char *str)
{
	int				i;
	unsigned int	base;

	i = 0;
	base = 0;
	while ('0' <= str[i] && str[i] <= '9')
		base = base * 10 + (str[i++] - '0');
	return (base);
}
