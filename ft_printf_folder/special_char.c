/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 12:54:12 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/13 02:52:57 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		special_char(char *c)
{
	return ((*c == '\0' || (*c == '{' && is_color(c)) || *c == '%') ? 1 : 0);
}

/*
** un_sc : untill_next_special_char
*/

size_t	ft_putstr_un_sc(char *format, t_pf *mai)
{
	size_t	i;

	i = 0;
	if (*(format + 0) == '\0')
	{
		return (0);
	}
	while (!(special_char(format + i)))
	{
		i++;
	}
	add_str_mai(format, i, mai);
	return (i);
}

size_t	ft_putstr_sc(char *format, va_list ap, t_pf *mai)
{
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
