/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:09:18 by lflandri          #+#    #+#             */
/*   Updated: 2022/08/02 10:13:23 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RECURCIVE_H
# define FT_RECURCIVE_H

struct s_square
{
	int x;
	int y;
	int size;
};

typedef struct s_square	t_square;

struct s_map {
    char        obstacle;
    char        clear;
    char        full;
    unsigned int    v_len;
    unsigned int    h_len;
};
typedef struct s_map    t_map_property;


#endif
