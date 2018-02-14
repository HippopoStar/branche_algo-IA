/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:44:25 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/14 18:09:18 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	flags(char *str, va_list ap, t_pf *mai)
{
	ssize_t	f_c_f;
	size_t	i;

	f_c_f = 0;
	i = 0;
	if (*(str + 0) == '%' && *(str + 1) == '%')
	{
		add_char_mai('%', mai);
		i = 2;
	}
	else if (!(*(str + 0) == '%' && (f_c_f = skip_padding(str + 1)) != -1))
	{
		error_code("invalid flag for \"ft_printf\"");
	}

	ssize_t	nb;
	nb = detect_mnoz((str + 1));
	ft_putnbr((int)nb);
	ft_putchar('\n');

	i = convers_flags(str + 1 + f_c_f, ap, mai, nb/*detect_mnoz((str + 1))*/);
	additionnal_flags(str + 1, mai);
	return (1 + (size_t)f_c_f + i);
}

size_t	convers_flags(char *str, va_list ap, t_pf *mai, ssize_t mnoz)
{
	size_t	i;
	ULLI	nb;

	i = 0;
	if ((i = skip_length_modifiers_and_conversion_specifier(str)) != 0)
	{
		length_modifier_anm(ap, str, mai, &nb);
		specify_base(*(str + i - 1), nb, mai, mnoz);
	}
	else if ((i = global_char_format(ap, str, mai)) != 0)
		;
	else if ((i = obsolete_convers(ap, *(str + 0), mai, mnoz)) != 0)
		;
	else
		error_code("Erreur dans \"ft_printf\"");
	return (i);
}
