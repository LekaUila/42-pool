/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 09:54:09 by nlocusso          #+#    #+#             */
/*   Updated: 2022/07/31 17:17:52 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_first_part(char *str, int i)
{
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] != ':')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == ':'))
			i++;
		else
			return (-1);
	}
	return (i);
}

int	check_second_part(char *str, int i)
{
	while (str[i] == ' ')
			i++;
	while (str[i] != '\n')
	{
		if (str[i] == '\0' && str[i - 1] == '\n')
			return (0);
		if (str[i] < 32 || str[i] == 127)
			return (-1);
		i++;
	}
	return (i);
}

int	check_dict(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == '\n')
			i++;
		if (check_first_part(str, i) == -1)
			return (1);
		else
			i = check_first_part(str, i);
		if (str[i] != ':')
			return (1);
		i++;
		if (check_second_part(str, i) == -1)
			return (1);
		else if (check_second_part(str, i) == 0)
			return (0);
		else
			i = check_second_part(str, i) + 1;
	}
	return (0);
}
