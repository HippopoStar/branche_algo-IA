/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:44:25 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/04 03:07:35 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	flags(char *str, va_list ap, t_pf *mai)
{
	ft_putstr("flags\n");

	size_t	i;
	int		d;
	char	c;
	char	*s;

	i = 0;
	if (!(strncmp("%d", str, 2)) && (i = 2) != 0)
	{
		d = va_arg(ap, int);
		add_int_mai(d, "0123456789", mai, 0);
	}
	else if (!(strncmp("%c", str, 2)) && (i = 2) != 0)
	{
		c = (char)va_arg(ap, int);
		add_char_mai(c, mai);
	}
	else if (!(strncmp("%s", str, 2)) && (i = 2) != 0)
	{
		s = va_arg(ap, char *);
		add_str_mai(s, mai);
	}
	return (i);
}
