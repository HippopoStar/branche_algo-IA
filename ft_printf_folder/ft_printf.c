/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:58:40 by lcabanes          #+#    #+#             */
/*   Updated: 2018/01/31 19:30:36 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	retour;
	char	c;
	size_t	i;

	va_start(ap, format);
	i = 0;
	while ((c = *(format + i)) != '\0')
	{
		if (c == '{' && (retour = colors((char *)(format + i))))
			i = i + retour;
		else if (c == '%' && (retour = flags((char *)(format + i), ap)))
			i = i + retour;
		if ((c == '{' || c == '%') && retour == 0)
		{
			write(1, (format + i), 1);
			i++;
		}
		retour = 0;
		while ((c = *(format + i + retour)) != '\0' && c != '{' && c != '%')
		{
			retour++;
		}
		write(1, (format + i), retour);
		i = i + retour;
	}
	va_end(ap);
	return (0);
}
