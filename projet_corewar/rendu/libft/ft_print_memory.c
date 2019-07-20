/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jates- <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:15:37 by jates-            #+#    #+#             */
/*   Updated: 2019/06/21 16:26:37 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BASE "0123456789abcdef"
#define BLANK NULL
#include "libft.h"

static void		ft_putptr_base_hex(unsigned int i, int deci)
{
	if (deci > 0)
	{
		if (i / 16 != 0)
			ft_putptr_base_hex(i / 16, deci - 1);
		while (i / 16 == 0 && deci > 1)
		{
			write(1, &(BASE[0]), 1);
			deci--;
		}
		write(1, &(BASE[i % 16]), 1);
	}
}

static void		ft_non_printable(unsigned char const *str, size_t nb)
{
	size_t i;

	i = 0;
	while (i < nb)
	{
		if (ft_isprint(str[i]))
			write(1, str + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
}

static void		ft_process(void const *ptr, unsigned char const *ligne, \
							size_t nb)
{
	int		i;
	int		k;
	size_t	adres;

	i = -1;
	k = -1;
	adres = (void const*)ptr - BLANK;
	ft_putptr_base_hex((unsigned int)adres, 8);
	write(1, ":", 1);
	while (k++ < 40)
	{
		if (i++ + 1 < (int)nb)
		{
			if (i % 2 == 0)
			{
				write(1, " ", 1);
				k++;
			}
			ft_putptr_base_hex((unsigned int)(ligne[i]), 2);
			k++;
		}
		else
			write(1, " ", 1);
	}
	ft_non_printable(ligne, nb);
}

void			*ft_print_memory(void const *addr, size_t size)
{
	unsigned char const		*str;

	str = (unsigned char const *)addr;
	if (!str)
	{
		ft_putptr_base_hex((unsigned int)((void const*)str - BLANK), 8);
		write(1, "\n", 1);
		return (0);
	}
	while ((int)size > 0)
	{
		if (!((int)size - 16 < 0))
			ft_process(addr, str, 16);
		else
			ft_process(addr, str, size);
		write(1, "\n", 1);
		str += 16;
		size -= 16;
	}
	return (0);
}
