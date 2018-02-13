/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_lm_anm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:52:00 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/11 18:24:59 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	lm_h_d(va_list ap, size_t i, t_pf *mai, ULLI *nb)
{
	long long int	p_nb;

	if (i == 1)
	{
		p_nb = (long long int)((short int)va_arg(ap, int));
	}
	else
	{
		p_nb = (long long int)((signed char)va_arg(ap, int));
	}
	if (p_nb < 0)
	{
		p_nb = -p_nb;
		mai->len = 1;
	}
	*nb = (unsigned long long int)p_nb;
}

void	lm_h_u(va_list ap, size_t i, ULLI *nb)
{
	if (i == 1)
	{
		*nb = (unsigned long long int)((unsigned short int)va_arg(ap, int));
	}
	else
	{
		*nb = (unsigned long long int)((unsigned char)va_arg(ap, int));
	}
}

void	lm_j(va_list ap, char c, t_pf *mai, ULLI *nb)
{
	long long int	p_nb;

	if (c == 'd' || c == 'i')
	{
		p_nb = (long long int)va_arg(ap, intmax_t);
		if (p_nb < 0)
		{
			p_nb = -p_nb;
			mai->len = 1;
		}
		*nb = (unsigned long long int)p_nb;
	}
	else
	{
		*nb = (unsigned long long int)va_arg(ap, uintmax_t);
	}
}

void	lm_z(va_list ap, char c, t_pf *mai, ULLI *nb)
{
	long long int	p_nb;

	if (c == 'd' || c == 'i')
	{
		p_nb = (long long int)va_arg(ap, ssize_t);
		if (p_nb < 0)
		{
			p_nb = -p_nb;
			mai->len = 1;
		}
		*nb = (unsigned long long int)p_nb;
	}
	else
	{
		*nb = (unsigned long long int)va_arg(ap, size_t);
	}
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