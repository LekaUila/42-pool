/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:17:28 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/15 17:17:31 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	if (*str == 0)
		return (1);
	if ((*str > 64 && *str < 91) || (*str > 96 && *str < 123))
		return (ft_str_is_alpha(++str));
	else
		return (0);
}
