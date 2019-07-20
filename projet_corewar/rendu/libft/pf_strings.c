/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:20:08 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/08 05:58:42 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	other_4str(size_t *e, t_conv conv, unsigned char b, size_t *r)
{
	if (b == 'c')
	{
		pf_putnchar(e['0'] ? '0' : ' ', e['W'] - 1, r);
		write(1, &conv.c, 1);
		*r += 1;
	}
	else
	{
		pf_putnchar(e['0'] ? '0' : ' ', e['W']\
				- (e['P'] && e['N'] > e['P'] ? e['P'] : e['N'])\
				, r);
		pf_putnstr(conv.s, (e['.'] && e['P'] < e['N']) ? e['P'] : e['N'], r);
	}
}

void	dash_4str(size_t *e, t_conv conv, unsigned char b, size_t *r)
{
	if (b == 'c')
	{
		write(1, &conv.c, 1);
		pf_putnchar(' ', e['W'] - 1, r);
		*r += 1;
	}
	else
	{
		pf_putnstr(conv.s, (e['.'] && e['P'] < e['N']) ? e['P'] : e['N'], r);
		pf_putnchar(' ', e['W']\
				- (e['P'] && e['N'] > e['P'] ? e['P'] : e['N'])\
				, r);
	}
}

void	strings(t_env *var, unsigned char b)
{
	is_csf(var->e, &var->conv, var->ap, b);
	b == 's' && var->conv.s ? var->e['N'] = ft_strlen(var->conv.s) :\
		(var->conv.s = "(null)")\
			&& (var->e['N'] = ft_strlen(var->conv.s));
	var->e['-'] ? dash_4str(&*var->e, var->conv, b, &var->r) :\
		other_4str(&*var->e, var->conv, b, &var->r);
}
