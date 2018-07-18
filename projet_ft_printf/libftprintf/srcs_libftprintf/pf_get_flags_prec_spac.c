/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_untill_format_or_conv_spec.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:22:37 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/18 14:21:52 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	pf_determinate_prec_and_spac(const char *format,\
													size_t *prec, size_t *spac)
{
	size_t	i;

	i = 0;
	if (*(format + i) == '.')
	{
		i++;
		*prec = (size_t)ft_atoi(format + i);
	}
	else
	{
		*spac = (size_t)ft_atoi(format + i);
	}
	while (ft_strchr("0123456789", (int)*(format + i)))
	{
		i++;
	}
	return (i);
}

static int		aux_pf_get_flags_prec_spac(const char *format,\
								char stock_flags[5], size_t *prec, size_t *spac)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (ft_strchr(PF_FLAGS, (int)*(format + i))
			|| ft_strchr("123456789", (int)*(format + i)))
	{
		if (ft_strchr(PF_FLAGS, (int)*(format + i))
				&& !ft_strchr(stock_flags, (int)*(format + i)))
		{
			*(stock_flags + j) = *(format + i);
			j++;
		}
		else
		{
			i = i + pf_determinate_prec_and_spac(format + i, prec, spac);
		}
		i++;
	}
	return (ft_strchr(PF_CONVERSION_SPECIFIERS, (int)*(format + i)) ?
			(int)i : -1);
}

int				pf_get_flags_prec_spac(const char *format,\
								char stock_flags[5], size_t *prec, size_t *spac)
{
	size_t	i;

	i = 0;
	while (i < 5)
	{
		*(stock_flags + i) = '\0';
		i++;
	}
	*prec = 0;
	*spac = 0;
	return (aux_pf_get_flags_prec_spac(format, stock_flags, prec, spac));
}
