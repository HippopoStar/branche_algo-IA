/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:58:40 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/01 14:26:08 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		aux_ft_printf(char *format, va_list ap)
{
	char	c;
	size_t	i;
	size_t	retour;

	i = 0;
	while ((c = *(format + i)) != '\0')
	{
		if (special_char(c))
		{
			if (!(retour = ft_putstr_sc(format + i, ap)))
			{
				ft_putchar(c);
				i++;
			}
			i = i + retour;
		}
		i = i + ft_putstr_un_sc((format + i));
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		retour;

	va_start(ap, format);
	retour = aux_ft_printf((char *)format, ap);
	va_end(ap);
	return (retour);
}
