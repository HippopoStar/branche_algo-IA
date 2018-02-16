/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:44:25 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/16 20:42:11 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	flags(char *str, va_list ap, t_pf *mai)
{
	size_t	i;
	size_t	total_opt_flags;

	i = 0;
	if (!(strncmp(str, "%%", 2)))
	{
		add_char_mai('%', mai);
		return (2);
	}
	total_opt_flags = skip_padding(str + 1);
	i = lm_cs_flags(str + 1 + total_opt_flags, ap, mai, detect_mnoz((str + 1)));
	optionnal_flags(str + 1, mai);
	return (1 + total_opt_flags + i);
}

size_t	lm_cs_flags(char *str, va_list ap, t_pf *mai, ssize_t mnoz)
{
	size_t	i;
	ULLI	nb;

	i = 0;
	if ((i = skip_leng_modi_and_conv_spec_for_integers(str)) != 0)
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
