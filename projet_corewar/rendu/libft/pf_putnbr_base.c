/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:56:28 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/08 05:37:11 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	e['H'] == # marker used in dash() from numbers.c
*/

#include "ft_printf.h"

unsigned char	itoc(size_t i, char b)
{
	if (i <= 9)
		return (i + '0');
	if (i >= 10 && i <= 36)
	{
		if (ft_isupper(b))
			return (i + 'A' - 10);
		return (i + 'a' - 10);
	}
	return (0);
}

void			pf_putnbr_base(unsigned long long unbr, char b, size_t *e,\
										size_t *r)
{
	unsigned char	base;

	base = get_base(b);
	if (e['#'] && b == 'o')
	{
		e['#'] = hash(&*e, unbr, b, r);
		e['H'] = 1;
	}
	if (unbr < base)
		pf_putchar(itoc(unbr % base, b), r);
	else
	{
		pf_putnbr_base(unbr / base, b, &*e, r);
		pf_putnbr_base(unbr % base, b, &*e, r);
	}
}
