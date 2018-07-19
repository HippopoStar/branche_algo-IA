/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 10:33:06 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/18 12:24:47 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_putstr("Appel de \"pf_convers\"\n");
*/

int	pf_convers(const char *format, va_list ap, t_list *mai)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (!(ft_strchr(FT_CONVERSION_SPECIFIERS, (int)*(format + i))
			|| ft_strchr(FT_FORMAT_SPECIFIERS, (int)*(format + i))
			|| *(format + i) == '\0'))
	{
		i++;
	}
	j = i;
	while (!(ft_strchr(FT_CONVERSION_SPECIFIERS, (int)*(format + j))
			|| *(format + j) == '\0'))
	{
		j++;
	}
	if (ft_strchr(FT_CHAR_CONV_SPEC, (int)*(format + j)))
	{
		return (pf_char_convers(format, ap, mai, format + i));
	}
	else if (ft_strchr(FT_SIGNED_CONV_SPEC, (int)*(format + j)))
	{
		return (pf_signed_convers(format, ap, mai, format + i));
	}
	else if (ft_strchr(FT_UNSIGNED_CONV_SPEC, (int)*(format + j)))
	{
		return (pf_unsigned_convers(format, ap, mai, format + i));
	}
	else
	{
		return (-1);
	}
}
