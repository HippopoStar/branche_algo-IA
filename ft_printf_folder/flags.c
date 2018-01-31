/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:44:25 by lcabanes          #+#    #+#             */
/*   Updated: 2018/01/31 19:00:49 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	flags(char *str, va_list ap)
{
	size_t	i;
	int		d;
	char	c;
	char	*s;

	i = 0;
	if (!(strncmp("%d", str, 2)) && (i = 2) != 0)
	{
		d = va_arg(ap, int);
		ft_putnbr(d);
	}
	else if (!(strncmp("%c", str, 2)) && (i = 2) != 0)
	{
		c = (char)va_arg(ap, int);
		ft_putchar(c);
	}
	else if (!(strncmp("%s", str, 2)) && (i = 2) != 0)
	{
		s = va_arg(ap, char *);
		ft_putstr(s);
	}
	return (i);
}
