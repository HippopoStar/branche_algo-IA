/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:05:30 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/19 11:23:57 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	%[flag][width][.precision][size-flag]type
*/

#include "ft_printf.h"

void		check_sizeflag(const char *format, size_t *i, size_t *e)
{
	if (format[*i] == 'h')
		(e[91] = (format[*i + 1] == 'h')) ? ++*i : ++e['h'];
	else if (format[*i] == 'l')
		(e[93] = (format[*i + 1] == 'l')) ? ++*i : ++e['l'];
	else
		++e['L'];
}

int			parse(const char *format, size_t *i, size_t *e)
{
	while (format[++*i])
	{
		if (pf_strchr("#0-+ ", format[*i]))
			++e[pf_strchr("#0-+ ", format[*i])];
		else if (ft_isdigit(format[*i]) && !e['W'])
		{
			e['W'] = pf_atoi(format, *i);
			*i += ft_nbrlen(e['W']) - 1;
		}
		else if (format[*i] == '.' && !e['.'])
		{
			++e['.'];
			e['P'] = pf_atoi(format, *i + 1);
			*i += ft_nbrlen(e['P']);
		}
		else if (pf_strchr("Lhl", format[*i]))
		{
			check_sizeflag(format, i, e);
			++*i;
			break ;
		}
		else
			break ;
	}
	return (pf_strchr("cspdiouxXfb", format[*i]));
}

void		pf_bzero(size_t *e, size_t len, t_conv *conv)
{
	while (len--)
		*e++ = 0;
	conv->nbr = 0;
	conv->unbr = 0;
	conv->dnbr = 0.0;
	conv->c = 0;
	conv->s = NULL;
}

static void	init_env(t_env *var, t_fptr *f)
{
	var->i = 0;
	var->r = 0;
	f['c'] = &strings;
	f['s'] = &strings;
	f['p'] = &numbers;
	f['d'] = &numbers;
	f['i'] = &numbers;
	f['o'] = &numbers;
	f['u'] = &numbers;
	f['x'] = &numbers;
	f['X'] = &numbers;
	f['f'] = &floats;
	f['b'] = &binarys;
}

int			ft_printf(const char *format, ...)
{
	t_env	var;
	t_fptr	f[128];

	va_start(var.ap, format);
	init_env(&var, &*f);
	while (format[var.i])
	{
		if (format[var.i] == '%')
		{
			if (format[var.i + 1] == '%')
				pf_putchar(format[++var.i], &var.r);
			else
			{
				pf_bzero(&*var.e, 127, &var.conv);
				!parse(format, &var.i, &*var.e) ? exit(EX_USAGE) :\
					f[pf_strchr("cspdiouxXfb", format[var.i])](&var,\
							format[var.i]);
			}
		}
		else
			pf_putchar(format[var.i], &var.r);
		++var.i;
	}
	va_end(var.ap);
	return (var.r);
}
