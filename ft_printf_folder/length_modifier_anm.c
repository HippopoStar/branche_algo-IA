/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_modifier_anm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:04:41 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/12 04:53:46 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	skip_length_modifiers_and_conversion_specifier(char *str)
{
	size_t	i;

	if (!(occurs(*(str + 0), "hljzdiouxX"))
		|| (*(str + 0) == 'l' && !occurs(*(str + 1), "cs")))
		return (0);
	i = 0;
	if (!(strncmp(str, "hh", 2)) || !(strncmp(str, "ll", 2)))
		i = 2;
	else if (occurs(*(str + 0), "hljz"))
		i = 1;
	if (*(str + 0) != 'l' && !(occurs(*(str + i), "diouxX")))
		error_code("Erreur dans \"ft_printf\"");
	return (i + 1);
}

void	fix_signed(va_list ap, size_t i, t_pf *mai, ULLI *nb)
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

void	fix_unsigned(va_list ap, size_t i, ULLI *nb)
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

size_t	length_modifier_anm(va_list ap, char *c_s, t_pf *mai, ULLI *nb)
{
	size_t	i;

	i = 0;
	if (occurs(*(c_s + i), "ldiouxX"))
	{
		if (*(c_s + i) == 'l')
		{
			i++;
			if (*(c_s + i) == 'l')
				i++;
		}
		(occurs(*(c_s + i), "di")) ?
			fix_signed(ap, i, mai, nb)
			: fix_unsigned(ap, i, nb);
		return (i + 1);
	}
	else if (occurs(*(c_s + 0), "hjz"))
	{
		i = aux_lm_anm(ap, c_s, mai, nb);
	}
	else
	{
		error_code("Erreur dans \"ft_printf\"");
	}
	return (0);
}
