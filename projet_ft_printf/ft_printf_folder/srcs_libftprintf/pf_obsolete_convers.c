/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obsolete_convers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 03:37:35 by lcabanes          #+#    #+#             */
/*   Updated: 2018/04/15 14:39:31 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_replace_left_spaces_by_zeros(t_pf *mai)
{
	size_t	i;

	i = 0;
	while (*(mai->str + i) == ' ')
	{
		*(mai->str + i) = '0';
		i++;
	}
}

size_t	pf_obsolete_convers(va_list ap, char c, t_pf *mai, ssize_t mnoz)
{
	ULLI	nb;

	if (pf_occurs(c, "DOU"))
	{
		if (c == 'D')
		{
			pf_length_modifier_anm(ap, "ld", mai, &nb);
			pf_specify_base('d', nb, mai, mnoz);
		}
		else if (c == 'O')
		{
			pf_length_modifier_anm(ap, "lo", mai, &nb);
			pf_specify_base('o', nb, mai, mnoz);
		}
		else
		{
			pf_length_modifier_anm(ap, "lu", mai, &nb);
			pf_specify_base('u', nb, mai, mnoz);
		}
		return (1);
	}
	return (0);
}
