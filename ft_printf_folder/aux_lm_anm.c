/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_lm_anm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:52:00 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/11 17:11:13 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	lm_h_d(va_list ap, size_t i, t_pf *mai, ULLI *nb)
{
}

void	lm_h_u(va_list ap, size_t i, ULLI *nb)
{
}

void	lm_j(va_list ap, char c, t_pf *mai, ULLI *nb)
{
}

void	lm_z(va_list ap, char c, t_pf *mai, ULLI *nb)
{
}

size_t	aux_lm_anm(va_list ap, char *c_s, t_pf *mai, ULLI *nb)
{
	size_t	i;

	i = 0;
	if (*(c_s + i) == 'h')
	{
		i++;
		if (*(c_s + i) == 'h')
			i++;
		occurs(*(c_s + i), "di") ?
			lm_h_d(ap, i, mai, nb)
			: lm_h_u(ap, i, nb);
	}
	else if (*(c_s + 0) == 'j')
	{
		i++;
		lm_j(ap, *(c_s + 1), mai, nb);
	}
	else
	{
		i++;
		lm_z(ap, *(c_s + 1), mai, nb);
	}
	return (i + 1);
}
