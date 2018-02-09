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

void	ls_aim_bis(void)
{
}

/*
** ls_aim = length_specificier_add_int_mai
*/

void	ls_anm(va_list ap, char *conv_spec, t_pf *mai, ssize_t mnoz)
{
	int						a;
	unsigned int			b;
	long int				c;
	unsigned long int		d;
	long long int			e;
	unsigned long long int	f;

	a = (!(strncmp(conv_spec, "d", 1)) || !(strncmp(conv_spec, "i", 1))) ?
		va_arg(ap, int) : 0;
	b = (!(strncmp(conv_spec, "ud", 2)) || !(strncmp(conv_spec, "ui", 2))) ?
		va_arg(ap, unsigned int) : 0;
	c = (!(strncmp(conv_spec, "ld", 2)) || !(strncmp(conv_spec, "li", 2))) ?
		va_arg(ap, long int) : 0;
	d = (!(strncmp(conv_spec, "uld", 3)) || !(strncmp(conv_spec, "uli", 3))) ?
		va_arg(ap, unsigned long int) : 0;
	e = (!(strncmp(conv_spec, "lld", 3)) || !(strncmp(conv_spec, "lli", 3))) ?
		va_arg(ap, long long int) : 0;
	f = (!(strncmp(conv_spec, "ulld", 4)) || !(strncmp(conv_spec, "ulli", 4))) ?
		va_arg(ap, unsigned long long int) : 0;
	((a < 0 && (mai->len = 1) && ((a == INT_MIN && (f = (ulli)(INT_MAX_PLUS_1))) || (f = (ulli)(-a))))
	|| (a != 0 && (f = (ulli)(a)))
	|| (b != 0 && (f = (ulli)b))
	|| (c < 0 && (mai->len = 1) && ((c == LONG_MIN && (f = (ulli)(LONG_MAX_PLUS_1))) || (f = (ulli)(-c))))
	|| (c != 0 && (f = (ulli)c))
	|| (d != 0 && (f = (ulli)d))
/*	|| (e < 0 && (mai->len = 1) && ((e == LLONG_MIN && (f = LLONG_MAX_PLUS_1)) || (f = (ulli)(-e))))
	|| (e != 0 && (f = (ulli)e))
	|| f != 0*/) ?
	add_nb_mai(f, "0123456789", mai, mnoz) : add_char_mai('V', mai) ;
}
