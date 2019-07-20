/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_binarys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:08:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/08 05:35:44 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putbin(size_t *e, long long nbr, size_t *r)
{
	unsigned char	k;

	if ((e['#'] || (int)nbr < 0) && !e['0'])
	{
		e['N'] % 4 == 0 ? e['N'] += 1 : e['N'];
		while (e['N'])
		{
			if (e['N'] % ((int)nbr > 0 ? 4 : 8) == 0)
				break ;
			++e['N'];
		}
	}
	*r += e['N'];
	while (e['N']--)
	{
		k = nbr >> e['N'];
		k & 1 ? write(1, "1", 1) : write(1, "0", 1);
		if (e['#'] && e['N'] % 4 == 0 && e['N'] != 0)
			pf_putchar(' ', r);
	}
}

void	other_4bin(size_t *e, long long nbr, size_t *r)
{
	if (!e['.'])
	{
		if (e['W'] && !e['#'])
			pf_putnchar(' ', e['W']\
					- (e['N'] + e['P'] <= 32 ? e['N'] + e['P'] : e['N'])\
					, r);
		pf_putbin(&*e, nbr, r);
	}
	else if (e['P'] > e['N'] && e['P'] + e['N'] < 32)
		pf_putbin(&*e, nbr, r);
	else
	{
		pf_putbin(&*e, nbr, r);
		e['P'] + e['N'] < 32 ? pf_putnchar(' ', e['W'] - e['P'] - e['N'], r) :\
			pf_putnchar(' ', e['W'] - e['N'], r);
	}
}

void	dash_4bin(size_t *e, long long nbr, size_t *r)
{
	if (e['P'] > e['N'] && e['P'] + e['N'] <= 32)
		pf_putbin(&*e, nbr, r);
	else
		pf_putbin(&*e, nbr, r);
	if (!e['#'])
		e['P'] + e['N'] < 32 ? pf_putnchar(' ', e['W'] - e['N'], r) :\
			pf_putnchar(' ', e['W'] + e['P'], r);
}

void	binarys(t_env *var, unsigned char b)
{
	is_bdi(var->e, &var->conv.nbr, var->ap, b);
	var->e['0'] ? var->e['N'] = 32 :\
		(var->e['N'] = pf_nbrlen((int)var->conv.nbr, 'b'));
	var->e['-'] ? dash_4bin(&*var->e, var->conv.nbr, &var->r) :\
		other_4bin(&*var->e, var->conv.nbr, &var->r);
}
