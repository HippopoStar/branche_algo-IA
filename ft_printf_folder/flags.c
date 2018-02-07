/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:44:25 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/07 01:45:32 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	flags(char *str, va_list ap, t_pf *mai)
{
	ssize_t	f_c_f;
	size_t	i;
	char	tmp;

	f_c_f = 0;
	i = 0;
	if (*(str + 0) == '%' && *(str + 1) == '%')
	{
		add_char_mai('%', mai);
		i = 2;
	}
	else if (!(*(str + 0) == '%' && (f_c_f = go_to_convert_flags(str + 1)) != -1))
	{
		error_code("invalid flag for \"ft_printf\"");
	}
	i = convertion_flags(str + 1 + f_c_f, ap, mai);
	tmp = *(str + 1 + f_c_f);
	*(str + 1 + f_c_f) = '\0';
//	additionnal_flags(str + 1, mai);
	*(str + 1 + f_c_f) = tmp;
	return (1 + f_c_f + (size_t)i);
}

size_t	convertion_flags(char *str, va_list ap, t_pf *mai)
{
	size_t	i;
	int		d;
	char	c;
	char	*s;

	i = 0;
	if (!(strncmp("d", str, 1)) && (i = 1) != 0)
	{
		d = va_arg(ap, int);
		add_int_mai(d, "0123456789", mai, 0);
	}
	else if (!(strncmp("c", str, 1)) && (i = 1) != 0)
	{
		c = (char)va_arg(ap, int);
		add_char_mai(c, mai);
	}
	else if (!(strncmp("s", str, 1)) && (i = 1) != 0)
	{
		s = va_arg(ap, char *);
		add_str_mai(s, mai);
	}
	return (i);
}
