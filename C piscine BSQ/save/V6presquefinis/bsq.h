/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:56:40 by cchauvet          #+#    #+#             */
/*   Updated: 2022/08/03 10:06:14 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

struct s_map {
	char			obstacle;
	char			clear;
	char			full;
	unsigned int	v_len;
	unsigned int	h_len;
};
typedef struct s_map	t_map_property;
struct s_square
{
	int	x;
	int	y;
	int	size;
};
typedef struct s_square	t_square;
void			starting_crea_map(char *path, char *str_entry);
void			read_standart_entry(void);
void			free_map(char **map);
unsigned int	ft_atou(char *str);
unsigned int	ft_mapcmp(t_map_property p1, t_map_property p2);
int				ft_is_digit(char *str);
unsigned int	ft_contain_only(char **str, char *charset);
unsigned int	ft_tablen(char **tab);
char			**ft_atomap(char *str, t_map_property *property);
char			*ft_strcat(char *dest, char *src);
void			write_map(char **map, t_map_property map_p);
char			**ft_split(char *str, char *sep);
char			*ft_strndup(char *src, unsigned int n);
unsigned int	ft_strlen(char *str);
int				ft_strstr(char *str, char *to_find);
char			*ft_filereader(char *path);
void			replace_map(char **map, t_square squarre, t_map_property map_p);
t_square		point_checker(char	**map, t_map_property map_p);
#endif
