/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:14:28 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/31 15:50:59 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);

int	check_key(char *str)
{
	int					ind;
	static const char	*keys[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8",
		"9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
		"30", "40", "50", "60", "70", "80", "90", "100",
		"1000",
		"1000000",
		"1000000000",
		"1000000000000",
		"1000000000000000",
		"1000000000000000000",
		"1000000000000000000000",
		"1000000000000000000000000",
		"1000000000000000000000000000",
		"1000000000000000000000000000000",
		"1000000000000000000000000000000000",
		"1000000000000000000000000000000000000"};

	ind = -1;
	while (++ind != 41)
	{
		if (!(ft_strstr(str, (char *) keys[ind])))
			return (0);
	}
	return (1);
}
