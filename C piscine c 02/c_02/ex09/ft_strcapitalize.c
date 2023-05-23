/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:43:11 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/16 12:43:12 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	tout(char *test, char boo)
{
	while (*(++test) != 0)
	{
		if (*test > 64 && *test < 91)
		{
			if (boo)
				*test = *test + 32;
			else
				boo = 1;
		}
		else if (*test > 96 && *test < 123)
		{
			if (!(boo))
				*test = *test - 32;
			if (!(boo))
				boo = 1;
		}
		else if (*test > 47 && *test < 58)
			boo = 1;
		else
			boo = 0;
	}
}

char	*ft_strcapitalize(char *str)
{	
	char	*test;
	char	boo;

	test = str - 1;
	boo = 0;
	tout(test, boo);
	return (str);
}
