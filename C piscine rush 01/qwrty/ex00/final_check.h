/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 12:17:23 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/24 12:17:25 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FINAL_CHECK_H
# define FINAL_CHECK_H

# include "map.h"

void	reset_counter(int max_values[2], int counters[2]);
void	ft_check_map_step1(int i, int max_values[2],
			int counters[2], char map[MAP_SIZE][MAP_SIZE]);
void	ft_check_map_step2(int i, int max_values[2],
			int counters[2], char map[MAP_SIZE][MAP_SIZE]);
#endif
