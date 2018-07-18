/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 12:54:12 by lcabanes          #+#    #+#             */
/*   Updated: 2018/04/15 14:48:27 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Concernant le caractere special '\\' :
**
** Les caracteres d'echappement ne sont a prendre en consideration que dans
** l'eventualite d'une utilisation future de "ft_printf" depuis un terminal
** par l'intermediaire de argc/argv
*/

int		pf_special_char(char *c)
{
	return ((*c == '\0' || (*c == '{' && pf_is_color(c)) || *c == '%') ? 1 : 0);
}

/*
** un_sc : untill_next_special_char
*/

size_t	pf_ft_putstr_un_sc(char *format, t_pf *mai)
{
	size_t	i;

	i = 0;
	if (*(format + 0) == '\0')
	{
		return (0);
	}
	while (!(pf_special_char(format + i)))
	{
		i++;
	}
	pf_add_str_mai(format, i, mai);
	return (i);
}

/*
** Concernant le caractere special '\\' :
**
**	else if (c == '\\' && (retour = escape((format + i), mai)))
**		i = i + retour;
*/

size_t	pf_ft_putstr_sc(char *format, va_list ap, t_pf *mai)
{
	size_t	retour;
	size_t	i;
	char	c;

	c = *(format + 0);
	i = 0;
	if (c == '{' && (retour = pf_colors((format + i), mai)))
		i = i + retour;
	else if (c == '%' && (retour = pf_flags((format + i), ap, mai)))
		i = i + retour;
	return (i);
}
