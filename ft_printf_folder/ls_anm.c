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

/*
void	aux_1_fs(va_list ap, size_t i, t_pf *mai, ulli *nb)
{
	long long int	c;

	(void)i;
	c = va_arg(ap, long long int);
	if (c < 0)
	{
		if (c == LLONG_MIN)
		{
			*nb = LLONG_MAX;
			(*nb)++;
		}
		else
			*nb = (ulli)(-c);
		mai->len = 1;
	}
	else
		*nb = (ulli)c;
}
*/

void	aux_0_fs(va_list ap, size_t i, t_pf *mai, ulli *nb)
{
	long int	b;

	if (i == 1)
	{
		b = va_arg(ap, long int);
		if (b < 0)
		{
			if (b == LONG_MIN)
			{
				*nb = LONG_MAX;
				(*nb)++;
			}
			else
				*nb = (ulli)(-b);
			mai->len = 1;
		}
		else
			*nb = (ulli)b;
	}
/*
	else
		aux_1_fs(ap, i, mai, nb);
*/
}

void	fix_signed(va_list ap, size_t i, t_pf *mai, ulli *nb)
{
	int		a;

	if (i == 0)
	{
		a = va_arg(ap, int);
		if (a < 0)
		{
			if (a == INT_MIN)
			{
				*nb = INT_MAX;
				(*nb)++;
			}
			else
				*nb = (ulli)(-a);
			mai->len = 1;
		}
		else
			*nb = (ulli)a;
	}
	else
		aux_0_fs(ap, i, mai, nb);
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
** ls_aim = length_specificier_add_int_mai
** c_s    = conversion_specificier
*/

size_t	ls_anm(va_list ap, char *c_s, t_pf *mai, ulli *nb)
{
	size_t	i;

	i = 0;
	if (occurs(*c_s, "di"))
		fix_signed(ap, i, mai, nb);
	else if (!(strncmp(c_s, "l", 1)))
	{
		i++;
		if (!(strncmp(c_s, "ll", 2)))
			i++;
		fix_signed(ap, i, mai, nb);
	}
	if (!(strncmp(c_s, "u", 1)))
	{
		i++;
		if (!(strncmp(c_s, "ul", 2)))
		{
			i++;
			if (!(strncmp(c_s, "ull", 3)))
				i++;
		}
		fix_unsigned(ap, i, nb);
	}
	return (i);
}
