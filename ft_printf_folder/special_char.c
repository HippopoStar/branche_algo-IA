/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 12:54:12 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/04 03:50:34 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		special_char(char c)
{
	ft_putstr("special_char\n");

	return ((c == '\0' || c == '{' || c == '%' || c == '\\') ? 1 : 0);
}

/*
** un_sc : untill_next_special_char
*/

size_t	ft_putstr_un_sc(char *format, t_pf *mai)
{
	ft_putstr("ft_putstr_un_sc\n");

	size_t	i;
	char	tmp;

	i = 0;
	while (!(special_char(*(format + i))))
	{
		i++;
	}
	tmp = *(format + i);
	*(format + i) = '\0';
	add_str_mai(format, mai);
	*(format + i) = tmp;
	return (i);
}

size_t	ft_putstr_sc(char *format, va_list ap, t_pf *mai)
{
	ft_putstr("ft_putstr_sc\n");

	size_t	retour;
	size_t	i;
	char	c;

	c = *(format + 0);
	i = 0;
	if (c == '\\' && (retour = escape((format + i), mai)))
		i = i + retour;
	else if (c == '{' && (retour = colors((format + i), mai)))
		i = i + retour;
	else if (c == '%' && (retour = flags((format + i), ap, mai)))
		i = i + retour;
	return (i);
}
