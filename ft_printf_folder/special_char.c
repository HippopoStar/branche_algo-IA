/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 12:54:12 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/01 14:16:54 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		special_char(char c)
{
	return ((c == '\0' || c == '{' || c == '%' || c == '\\') ? 1 : 0);
}

/*
** un_sc : untill_next_special_char
*/

size_t	ft_putstr_un_sc(char *format)
{
	size_t	i;

	i = 0;
	while (!(special_char(*(format + i))))
	{
		i++;
	}
	write(1, format, i);
	return (i);
}

size_t	ft_putstr_sc(char *format, va_list ap)
{
	size_t	retour;
	size_t	i;
	char	c;

	c = *(format + 0);
	i = 0;
	if (c == '\\' && (retour = escape(format + i)))
		i = i + retour;
	else if (c == '{' && (retour = colors(format + i)))
		i = i + retour;
	else if (c == '%' && (retour = flags(format + i, ap)))
		i = i + retour;
	return (i);
}
