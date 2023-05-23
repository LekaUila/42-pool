/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:09:15 by lflandri          #+#    #+#             */
/*   Updated: 2022/08/02 18:37:53 by cchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	init_t_squarre(t_square *square, int x, int y, int size)
{
	(*square).size = size;
	(*square).x = x;
	(*square).y = y;
}

t_square	find_the_biggest_square(t_square square1, t_square square2)
{
	if (square1.size >= square2.size)
		return (square1);
	return (square2);
}

int	right_bottom_square_checker(t_square square,
		unsigned int ind, char	**map, t_map_property map_p)
{
	unsigned int	ind2;

	ind2 = 0;
	while (ind2 != ind + 1)
	{
		if (map[square.y + ind][square.x + ind2] != map_p.obstacle
			&& map[square.y + ind2][square.x + ind] != map_p.obstacle)
			ind2++;
		else
			return (0);
	}
	return (1);
}

t_square	left_top_square_checker(t_square square, char	**map,
		t_map_property map_p)
{
	unsigned int	ind;

	ind = 0;
	while (square.x + ind != map_p.h_len && square.y + ind != map_p.v_len
		&& map[square.y + ind][square.x] != map_p.obstacle
		&& map[square.y][square.x + ind] != map_p.obstacle)
	{
		if (right_bottom_square_checker(square, ind, map, map_p))
			square.size = ind + 1;
		else
			return (square);
		ind++;
	}
	return (square);
}

t_square	point_checker(char	**map, t_map_property map_p)
{
	t_square		big_square;
	t_square		new_square;
	unsigned int	ind_w;
	unsigned int	ind_h;

	ind_h = -1;
	big_square.size = 0;
	while (++ind_h != map_p.v_len)
	{
		ind_w = -1;
		while (++ind_w != map_p.h_len)
		{
			init_t_squarre(&new_square, ind_w, ind_h, 0);
			new_square = left_top_square_checker(new_square, map, map_p);
			big_square = find_the_biggest_square(big_square, new_square);
		}
	}
	return (big_square);
}

/*

#include <stdio.h>

int main(void)
{
t_square coucou;


t_map_property	map_p;
    map_p.obstacle = 'o';
    map_p.clear = '.';
    map_p.full = 'x';
    map_p.v_len = 5;
	map_p.h_len = 5;

char *map[] = 
{".o...",
 "oo..o",
 "..oo.",
 ".....",
 "..o.o"};
 


t_map_property	map_p;
    map_p.obstacle = 'o';
    map_p.clear = '.';
    map_p.full = 'x';
    map_p.v_len = 30;
	map_p.h_len = 30;

char *map[] = 
{"o....oo...o.o.o..ooo...o....oo",
 "...o..oo......oo.o..o......o.o",
 "ooo........o..o.o..oo......ooo",
 "o......oo...o....oooo..o....o.",
 "......oo.........o..o.....o...",
 ".o....o.......o.o.oooo...ooo..",
 ".oo.o.oo.ooo.....oo.ooo.o.o.o.",
 "oo...o.o...o..o.o..oooo....oo.",
 "..ooo.oo....o..o.oo..o........",
 "...o.oooo.....ooo..o........o.",
 "o............oooo.o.o..oo.o.oo",
 "o....o...oo....o.o....o.o.....",
 "..o.o...o...oo..ooo......o....",
 "o....o.........o...o....oo....",
 "oo..o.......ooo...o...o.ooo.oo",
 "o.o.....oo..oo.oo....o.oo.oo.o",
 ".o.o..o.oo.oo..o.oo.oo.o.o.o.o",
 ".o.o.....oo.o.o...o..o.oo....o",
 "....o..oo..o...oo..o....o.o...",
 "oo.o............o...o..oo..o..",
 ".........o..o.oo..ooo..o..o..o",
 "..o.ooooo...o.o...o.oo.o.o.ooo",
 ".o....o...oooo..o......o.o....",
 "o...ooo.....oo..o....o..ooo..o",
 ".o...oo.o.....o.o.....o......o",
 "o...oo.........o..o.......o...",
 "oo.....oo.....o....oo.oo......",
 ".........o......oo.o.oo.o.o.o.",
 "o.o..o...o.o.....o.oo...oo..o.",
 "..oo...o.oo.ooo..oo.o.o......o"};
 

coucou = point_checker(map, map_p);
//replace_map(map, coucou, map_p);
printf ("%d\n", coucou.x);
printf ("%d\n", coucou.y);
printf ("%d\n", coucou.size);
//write_map(map, map_p);
}
*/
