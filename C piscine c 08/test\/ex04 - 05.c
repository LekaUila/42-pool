/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04 - 05.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:01:55 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/28 10:47:00 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_stock_str *ft_strs_to_tab(int ac, char **av);
void ft_show_tab(struct s_stock_str *par);


int main(int ac, char **av)
{
	ft_show_tab(ft_strs_to_tab(ac, av));
	return(0);
}