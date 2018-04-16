/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_modifier_anm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:04:41 by lcabanes          #+#    #+#             */
/*   Updated: 2018/04/17 01:53:09 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_fix_signed(va_list ap, size_t i, t_pf *mai, ULLI *nb)
{
	long long int	l_n;

	if (i == 0)
		l_n = (long long int)va_arg(ap, int);
	else if (i == 1)
		l_n = (long long int)va_arg(ap, long int);
	else
		l_n = va_arg(ap, long long int);
	if (l_n < 0)
	{
		if (l_n == LLONG_MIN)
		{
			*nb = LLONG_MAX;
			(*nb)++;
		}
		else
			*nb = (ULLI)(-l_n);
		mai->len = 1;
	}
	else
		*nb = (ULLI)l_n;
}

void	pf_fix_unsigned(va_list ap, size_t i, ULLI *nb)
{
	if (i == 0)
	{
		*nb = (ULLI)va_arg(ap, unsigned int);
	}
	else if (i == 1)
	{
		*nb = (ULLI)va_arg(ap, unsigned long int);
	}
	else
	{
		*nb = va_arg(ap, unsigned long long int);
	}
}

/*
** _anm = _add_int_mai
** c_s  = conversion_specifier
*/

size_t	pf_length_modifier_anm(va_list ap, char *c_s, t_pf *mai, ULLI *nb)
{
	size_t	i;

	i = 0;
	if (pf_occurs(*(c_s + i), "ldiouxX"))
	{
		if (*(c_s + i) == 'l')
		{
			i++;
			if (*(c_s + i) == 'l')
				i++;
		}
		(pf_occurs(*(c_s + i), "di")) ?
			pf_fix_signed(ap, i, mai, nb)
			: pf_fix_unsigned(ap, i, nb);
		return (i + 1);
	}
	else if (pf_occurs(*(c_s + 0), "hjz"))
	{
		i = pf_aux_lm_anm(ap, c_s, mai, nb);
	}
	else if (*(c_s + 0) == 'p')
	{
		*nb = (ULLI)va_arg(ap, void *);
	}
	else
	{
		pf_error_code("Erreur dans \"length_modifier_anm.c\\length_mod[...]\"");
	}
	return (0);
}
