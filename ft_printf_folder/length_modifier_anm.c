/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_anm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 07:34:46 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/09 09:42:21 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Changer le header de ce fichier

size_t	skip_length_modifier(char *str)
{
	size_t	i;

	if (!(occurs(*(str + i), "hljzdiouxX")))
		return (0);
	i = 0;
	if (!(strncmp(str, "hh", 2)) || !(strncmp(str, "ll", 2)))
		i = 2;
	else if (occurs(*(str + 0), "hljz"))
		i = 1;
	if (!(occurs(*(str + i), "diouxX")))
		error_code("Erreur dans \"ft_printf\"");
	return (i + 1);
}

void	fix_signed(va_list ap, size_t i, t_pf *mai, ulli *nb)
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
			*nb = (ulli)(-l_n);
		mai->len = 1;
	}
	else
		*nb = (ulli)l_n;
}

void	fix_unsigned(va_list ap, size_t i, ulli *nb)
{
	if (i == 0)
	{
		*nb = (ulli)va_arg(ap, unsigned int);
	}
	else if (i == 1)
	{
		*nb = (ulli)va_arg(ap, unsigned long int);
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

size_t	length_modifier_anm(va_list ap, char *c_s, t_pf *mai, ulli *nb)
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
		(occurs(*(c_s + i), "di")) ? fix_signed(ap, i, mai, nb) : fix_unsigned(ap, i, nb);
		return (i + 1);
	}
	error_code("Flag pas encore gere");
	return (0);
}
