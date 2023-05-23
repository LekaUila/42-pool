/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:01:11 by maldavid          #+#    #+#             */
/*   Updated: 2022/07/23 19:08:41 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define MAP_SIZE 4

typedef enum __attribute__((__packed__)) e_bool { false = 0, true = 1}	t_bool;

void	ft_init_map(void);
t_bool	ft_fill_map(char *border_values);
t_bool	ft_check_map(char map[MAP_SIZE][MAP_SIZE]);
void	ft_print_map(char map[MAP_SIZE][MAP_SIZE]);

#endif
