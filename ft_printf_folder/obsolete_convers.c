/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obsolete_convers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 03:37:35 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/12 03:37:49 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	obsolete_convers(va_list ap, char c, t_pf *mai, ssize_t mnoz)
{
	ULLI	nb;

	if (occurs(c, "DOU"))
	{
		if (c == 'D')
		{
			length_modifier_anm(ap, "ld", mai, &nb);
			specify_base('d', nb, mai, mnoz);
		}
		else if (c == 'O')
		{
			length_modifier_anm(ap, "lo", mai, &nb);
			specify_base('o', nb, mai, mnoz);
		}
		else
		{
			length_modifier_anm(ap, "lu", mai, &nb);
			specify_base('u', nb, mai, mnoz);
		}
		return (1);
	}
	return (0);
}