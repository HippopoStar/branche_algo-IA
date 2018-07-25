/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unsigned_convers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 07:46:27 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/25 08:06:59 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_putstr("Appel de \"aux1_pf_get_unsigned\"\n");
*/

static int	aux1_pf_get_unsigned(unsigned long long int *n, va_list ap,\
															const char *type)
{
	if (pf_jump_to_conv_spec(type) == 'p')
	{
		*n = (unsigned long long int)va_arg(ap, void *);
	}
	else if (!ft_strncmp("ju", type, 2) || !ft_strncmp("jo", type, 2)
		|| !ft_strncmp("jx", type, 2) || !ft_strncmp("jX", type, 2)
		|| !ft_strncmp("jb", type, 2) || !ft_strncmp("jB", type, 2))
	{
		*n = (unsigned long long int)va_arg(ap, uintmax_t);
	}
	else if (!ft_strncmp("zu", type, 2) || !ft_strncmp("zo", type, 2)
		|| !ft_strncmp("zx", type, 2) || !ft_strncmp("zX", type, 2)
		|| !ft_strncmp("zb", type, 2) || !ft_strncmp("zB", type, 2))
	{
		*n = (unsigned long long int)va_arg(ap, size_t);
	}
	else
	{
		return (-1);
	}
	return (0);
}

/*
**	ft_putstr("Appel de \"aux0_pf_get_unsigned\"\n");
*/

static int	aux0_pf_get_unsigned(unsigned long long int *n, va_list ap,\
															const char *type)
{
	if (!ft_strncmp("hu", type, 2) || !ft_strncmp("ho", type, 2)
		|| !ft_strncmp("hx", type, 2) || !ft_strncmp("hX", type, 2)
		|| !ft_strncmp("hb", type, 2) || !ft_strncmp("hB", type, 2))
	{
		*n = (unsigned long long int)((unsigned short int)\
													va_arg(ap, unsigned int));
	}
	else if (!ft_strncmp("hhu", type, 3) || !ft_strncmp("hho", type, 3)
		|| !ft_strncmp("hhx", type, 3) || !ft_strncmp("hhX", type, 3)
		|| !ft_strncmp("hhb", type, 3) || !ft_strncmp("hhB", type, 3))
	{
		*n = (unsigned long long int)((unsigned char)va_arg(ap, unsigned int));
	}
	else
	{
		return (aux1_pf_get_unsigned(n, ap, type));
	}
	return (0);
}

/*
**	ft_putstr("Appel de \"pf_get_unsigned\"\n");
*/

static int	pf_get_unsigned(unsigned long long int *n, va_list ap,\
															const char *type)
{
	if (*type == 'u' || *type == 'o' || *type == 'x' || *type == 'X'
		|| *type == 'b' || *type == 'B')
	{
		*n = (unsigned long long int)va_arg(ap, unsigned int);
	}
	else if (!ft_strncmp("llu", type, 3) || !ft_strncmp("llo", type, 3)
		|| !ft_strncmp("llx", type, 3) || !ft_strncmp("llX", type, 3)
		|| !ft_strncmp("llb", type, 3) || !ft_strncmp("llB", type, 3)
		|| !ft_strncmp("lU", type, 2) || !ft_strncmp("lO", type, 2))
	{
		*n = va_arg(ap, unsigned long long int);
	}
	else if (!ft_strncmp("lu", type, 2) || !ft_strncmp("lo", type, 2)
		|| !ft_strncmp("lx", type, 2) || !ft_strncmp("lX", type, 2)
		|| !ft_strncmp("lb", type, 2) || !ft_strncmp("lB", type, 2)
		|| ft_strchr("UO", (int)pf_jump_to_conv_spec(type)))
	{
		*n = (unsigned long long int)va_arg(ap, unsigned long int);
	}
	else
	{
		return (aux0_pf_get_unsigned(n, ap, type));
	}
	return (0);
}

/*
**	ft_putstr("Appel de \"aux_pf_unsigned_convers\"\n");
*/

static char	*aux_pf_unsigned_convers(unsigned long long int n, size_t prec,\
													size_t spac, char conv_spec)
{
	if (conv_spec == 'u' || conv_spec == 'U')
	{
		return (ft_ullitoa_base(n, "0123456789", prec, spac));
	}
	else if (conv_spec == 'o' || conv_spec == 'O')
	{
		return (ft_ullitoa_base(n, "01234567", prec, spac));
	}
	else if (conv_spec == 'x' || conv_spec == 'p')
	{
		return (ft_ullitoa_base(n, "0123456789abcdef", prec, spac));
	}
	else if (conv_spec == 'X')
	{
		return (ft_ullitoa_base(n, "0123456789ABCDEF", prec, spac));
	}
	else if (conv_spec == 'b' || conv_spec == 'B')
	{
		return (ft_ullitoa_base(n, "01", prec, spac));
	}
	else
	{
		return (NULL);
	}
}

/*
**	ft_putstr("Appel de \"pf_unsigned_convers\"\n");
*/

int			pf_unsigned_convers(const char *format, va_list ap,\
												t_list *mai, const char *type)
{
	unsigned long long int	n;
	size_t					prec;
	size_t					spac;
	char					conv_spec;

	if (pf_get_unsigned(&n, ap, type) == -1)
		return (-1);
	pf_get_prec_and_spac(format, &prec, &spac);
	conv_spec = pf_jump_to_conv_spec(type);
	if (n == 0 && pf_is_flag_present(format, '.') && prec == 0
	&& !(ft_strchr("oO", (int)conv_spec) && pf_is_flag_present(format, '#')))
		return (((mai->content = pf_malloc_and_left_spaces(spac, 0)) ? 0 : -1));
	if (((n != 0 || ft_strchr("oO", (int)conv_spec))
				&& pf_is_flag_present(format, '#')) || conv_spec == 'p')
		pf_anticipate_sharp_mark(n, conv_spec, &prec);
	if (!(mai->content = (void *)aux_pf_unsigned_convers(n, prec, spac,\
					conv_spec)))
		return (-1);
	pf_deal_zero(format, (char *)mai->content, 0);
	if ((n != 0 && pf_is_flag_present(format, '#')) || conv_spec == 'p')
		pf_apply_sharp_mark((char *)mai->content, conv_spec);
	pf_deal_minus_sign(format, (char *)mai->content, 0);
	return (0);
}
