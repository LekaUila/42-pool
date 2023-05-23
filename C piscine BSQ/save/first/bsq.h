/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvet <cchauvet@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:56:40 by cchauvet          #+#    #+#             */
/*   Updated: 2022/08/02 12:06:42 by cchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
struct s_map {
	char		obstacle;
	char		clear;
	char		full;
	unsigned int	v_len;
	unsigned int	h_len;
};
typedef struct s_map	t_map_property;
unsigned int			ft_atou(char *str);
int						ft_is_digit(char *str);
unsigned int			ft_containe_only(char *str, char *charset);
unsigned int			ft_tablen(char **tab);
char					**ft_atomap(char *str);
char					*ft_strcat(char *dest, char *dest);
void 					write_map(char **map, t_map_property map_p);
char					**ft_split(char *str, char *sep);
char					*ft_strndup(char *src, unsigned int n);
int						ft_strlen(char *str);
int						ft_strstr(char *str, char *to_find);
#endif
