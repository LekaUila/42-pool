/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracker.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:36:57 by maldavid          #+#    #+#             */
/*   Updated: 2022/07/23 19:37:04 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACKER_H
# define BACKTRACKER_H

# include "map.h"
# include "final_check.h"

t_bool	ft_recursive(char map[MAP_SIZE][MAP_SIZE], int i, int j);

#endif
