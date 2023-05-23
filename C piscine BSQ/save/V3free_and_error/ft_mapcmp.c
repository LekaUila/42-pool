/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvet <cchauvet@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:38:48 by cchauvet          #+#    #+#             */
/*   Updated: 2022/08/02 16:00:11 by cchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

unsigned int	ft_mapcmp(t_map_property p1, t_map_property p2)
{
	if (p1.obstacle != p2.obstacle)
		return (0);
	if (p1.clear != p2.clear)
		return (0);
	if (p1.full != p2.full)
		return (0);
	if (p1.v_len != p2.v_len)
		return (0);
	if (p1.h_len != p2.h_len)
		return (0);
	return (1);
}
