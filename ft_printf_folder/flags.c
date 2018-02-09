/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:44:25 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/09 07:48:49 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	flags(char *str, va_list ap, t_pf *mai)
{
	ssize_t	f_c_f;
	size_t	i;

	f_c_f = 0;
	i = 0;
	if (*(str + 0) == '%' && *(str + 1) == '%')
	{
		add_char_mai('%', mai);
		i = 2;
	}
	else if (!(*(str + 0) == '%' && (f_c_f = go_to_conv_flags(str + 1)) != -1))
	{
		error_code("invalid flag for \"ft_printf\"");
	}
	i = conversion_flags(str + 1 + f_c_f, ap, mai);
//	additionnal_flags(str + 1, i, mai);
	return (1 + (size_t)f_c_f + i);
}

size_t	conversion_flags(char *str, va_list ap, t_pf *mai)
{
	size_t	i;
	char	c;
	char	*s;

	i = 0;
	if (!(strncmp("d", str, 1)) && (i = 1) != 0)
	{
		ls_anm(ap, "d", mai, 0);
	}
	else if (!(strncmp("c", str, 1)) && (i = 1) != 0)
	{
		c = (char)va_arg(ap, int);
		add_char_mai(c, mai);
	}
	else if (!(strncmp("s", str, 1)) && (i = 1) != 0)
	{
		s = va_arg(ap, char *);
		add_str_mai(s, -1, mai);
	}
	return (i);
}
