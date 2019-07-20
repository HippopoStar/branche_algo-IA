/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:19:19 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/08 05:36:35 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sign(size_t *e, long long nbr, unsigned char b, size_t *r)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		++*r;
	}
	else if (e['+'] && !pf_strchr("ouxX", b))
	{
		nbr < 0 ? write(1, "-", 1) : write(1, "+", 1);
		++*r;
	}
	else if (e[' '] && !e['+'] && !pf_strchr("ouxX", b))
	{
		nbr < 0 ? write(1, "-", 1) : write(1, " ", 1);
		++*r;
	}
}

void	other(size_t *e, t_conv conv, unsigned char b, size_t *r)
{
	if (!e['.'])
	{
		if (e['0'])
			sign(&*e, conv.nbr, b, r);
		pf_putnchar(e['0'] ? '0' : ' ', e['W'] - e['N'] - ((e['+'] || e[' ']\
						|| conv.nbr < 0) && !pf_strchr("ouxX", b) ? 1 : 0)\
				- (e['#'] && b == 'o' && conv.unbr ? 1 : 0), r);
		if (!e['0'])
			sign(&*e, conv.nbr, b, r);
	}
	else
	{
		pf_putnchar(' ', e['W'] - (e['N'] > e['P'] ? e['N'] : e['P'])\
				- ((e['+'] || e[' '] || conv.nbr < 0)\
					&& !pf_strchr("ouxX", b) ? 1 : 0)\
				- (e['#'] && b == 'o' && e['P'] <= e['N'] ? 1 : 0), r);
		sign(&*e, conv.nbr, b, r);
		pf_putnchar('0', e['P'] - e['N'], r);
	}
	if (b == 'd' || b == 'i')
		e['.'] && conv.nbr == 0 ? 0 : pf_putnbr(conv.nbr, r);
	else if (e['#'] && b == 'o' && conv.unbr == 0)
		hash(e, conv.unbr, b, r);
	else
		e['.'] && conv.unbr == 0 ? 0 : pf_putnbr_base(conv.unbr, b, &*e, r);
}

void	dash(size_t *e, t_conv conv, unsigned char b, size_t *r)
{
	if ((e['#'] && (b == 'x' || b == 'X') && conv.unbr > 0) || b == 'p')
	{
		ft_isupper(b) ? write(1, "0X", 2) : write(1, "0x", 2);
		*r += 2;
	}
	else
		sign(&*e, conv.nbr, b, r);
	if (e['P'] > e['N'])
		pf_putnchar('0', e['P'] - e['N'], r);
	if (b == 'd' || b == 'i')
		e['.'] && conv.nbr == 0 ? 0 : pf_putnbr(conv.nbr, r);
	else if (b == 'o' && conv.unbr == 0 && e['#'])
		hash(e, conv.unbr, b, r);
	else
		e['.'] && conv.unbr == 0 ? 0 : pf_putnbr_base(conv.unbr, b, &*e, r);
	pf_putnchar(' ', e['W'] - (e['N'] > e['P'] ? e['N'] : e['P'])\
			- ((e['+'] || e[' '] || conv.nbr < 0)\
				&& !pf_strchr("ouxX", b) ? 1 : 0)\
			- ((e['H'] || e['#']) && b == 'o'\
				&& ((conv.unbr && !e['P'])\
					|| (e['.'] && e['P'] <= e['N'])) ? 1 : 0)\
			- ((e['#'] && (b == 'x' || b == 'X')\
				&& conv.unbr) || b == 'p' ? 2 : 0), r);
}

int		hash(size_t *e, unsigned long long unbr, unsigned char b, size_t *r)
{
	if (b == 'o')
		pf_putnchar('0', 1 - (e['P'] > e['N'] ? 1 : 0), r);
	else
	{
		if (!e['.'])
		{
			if (e['0'])
				ft_isupper(b) ? write(1, "0X", 2) : write(1, "0x", 2);
			pf_putnchar(e['0'] ? '0' : ' ', e['W'] - e['N'] - 2, r);
			if (!e['0'])
				ft_isupper(b) ? write(1, "0X", 2) : write(1, "0x", 2);
		}
		else
		{
			pf_putnchar(' ', e['W'] -\
					(e['N'] > e['P'] ? e['N'] + 2 : e['P'] + 2), r);
			ft_isupper(b) ? write(1, "0X", 2) : write(1, "0x", 2);
			pf_putnchar('0', e['P'] - e['N'], r);
		}
		e['.'] && unbr == 0 ? 0 : pf_putnbr_base(unbr, b, &*e, r);
		*r += 2;
	}
	return (0);
}

void	numbers(t_env *var, unsigned char b)
{
	(b == 'd' || b == 'i') ? is_bdi(var->e, &var->conv.nbr, var->ap, b) :\
		(is_ouxp(var->e, &var->conv.unbr, var->ap, b));
	var->e['N'] = (b == 'd' || b == 'i') ? pf_nbrlen(var->conv.nbr, b) :\
		pf_unbrlen(var->conv.unbr, b);
	if (var->e['.'] && var->conv.nbr == 0 && var->conv.unbr == 0)
		--var->e['N'];
	if ((var->e['#'] && !var->e['-'] && (b == 'x' || b == 'X')\
				&& var->conv.unbr > 0)\
			|| (!var->e['-'] && b == 'p'))
		hash(&*var->e, var->conv.unbr, b, &var->r);
	else if (var->e['-'])
		dash(&*var->e, var->conv, b, &var->r);
	else
		other(&*var->e, var->conv, b, &var->r);
}
