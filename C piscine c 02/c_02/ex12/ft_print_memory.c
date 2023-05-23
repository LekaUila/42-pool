/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:16:34 by lflandri          #+#    #+#             */
/*   Updated: 2022/07/17 16:30:36 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_int_to_hexa(char str)
{	
	char	table[16];
	int		n;

	n = -1;
	while (++n < 10)
		table[n] = n + 48;
	n = -1;
	while (++n < 6)
		table[n + 10] = 97 + n;
	return (*(table + str));
}

void	write_adress(unsigned long adr, char count)
{	
	unsigned long	nbhexa;

	if (adr)
	{
		write_adress(adr / 16, count - 1);
		nbhexa = ft_int_to_hexa(adr % 16);
		write(1, &nbhexa, 1);
	}
	else
	{
		while (count--)
		{
			write(1, "0", 1);
		}
	}	
}

void	write_hexa(char *addr, unsigned int size)
{
	int	count;
	int	str;

	count = 16;
	while (count-- && size--)
	{
		str = ft_int_to_hexa(*addr / 10);
		write(1, &str, 1);
		str = ft_int_to_hexa(*(addr++) % 10);
		write(1, &str, 1);
		if (size)
		{
			str = ft_int_to_hexa(*addr / 10);
			write(1, &str, 1);
			str = ft_int_to_hexa(*(addr++) % 10);
			write(1, &str, 1);
			size--;
		}
		count--;
		write(1, " ", 2);
	}
}

void	write_texte(char *addr, unsigned int size)
{
	int	count;

	count = 16;
	while (size-- > 0 && count-- > 0)
	{
		if (*addr < 32 || *addr == 127)
			write(1, ".", 1);
		else
			write(1, addr, 1);
		addr++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{	
	void			*save;
	unsigned long	adrr;

	adrr = (unsigned long) addr;
	save = addr;
	while (size)
	{	
		write_adress(adrr, 16);
		write(1, ": ", 2);
		write_hexa(addr, size);
		write_texte(addr, size);
		addr = addr + 16;
		write(1, "\n", 1);
		adrr = adrr + 16;
		if (size >= 16)
			size = size - 16;
		else
			size = 0;
	}
	return (save);
}
