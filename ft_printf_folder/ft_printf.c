/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:58:40 by lcabanes          #+#    #+#             */
/*   Updated: 2018/01/31 18:55:59 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;

	va_start(ap, format);
	i = 0;
	while (*(format + i) != '\0')
	{
		if (*(format + i) == '{')
		{
			i = i + colors((char *)(format + i));
		}
		if (*(format + i) == '%')
		{
			i = i + flags((char *)(format + i), ap);
		}
		write(1, (format + i), 1);
		i++;
	}
	va_end(ap);
	return (0);
}
