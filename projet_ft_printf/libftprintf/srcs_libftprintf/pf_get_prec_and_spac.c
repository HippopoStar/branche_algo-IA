/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_prec_and_spac.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:53:05 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/18 14:53:07 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_get_prec_and_spac(const char *format,\
													size_t *prec, size_t *spac)
{
	size_t	i;

	*prec = 0;
	*spac = 0;
	i = 0;
	while (!ft_strchr(PF_FORMAT_SPECIFIERS, (int)*(format + i))
			&& !ft_strchr(PF_CONVERSION_SPECIFIERS, (int)*(format + i))
			&& !(*(format + i) == '\0'))
	{
		if (*(format + i) == '.' || ft_strchr("123456789", (int)*(format + i)))
		{
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
		}
		else
		{
			i++;
		}
	}
	return (!(*(format + i) == '\0') ? (int)i : -1);
}
