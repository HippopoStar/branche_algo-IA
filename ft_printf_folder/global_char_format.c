/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_char_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 02:46:22 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/12 03:21:47 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_format(va_list ap, char c, t_pf *mai)
{
	char	character;

	character = (c == 'c') ?
		(char)va_arg(ap, int) : (char)((wint_t)va_arg(ap, int));
	add_char_mai(character, mai);
}

void	char_star_format(va_list ap, char c, t_pf *mai)
{
	char	*string;

	string = (c == 's') ? va_arg(ap, char *) : (char *)va_arg(ap, wchar_t *);
	add_str_mai(string, -1, mai);
}

size_t	global_char_format(va_list ap, char *str, t_pf *mai)
{
	size_t	i;

	i = 0;
	if (((*(str + 0) == 'c' || *(str + 0) == 'C') && (i = 1) != 0)
		|| ((*(str + 0) == 'l' && *(str + 1) == 'c') && (i = 2) != 0))
	{
		char_format(ap, *(str + 0), mai);
	}
	else if (((*(str + 0) == 's' || *(str + 0) == 'S') && (i = 1) != 0)
		|| ((*(str + 0) == 'l' && *(str + 1) == 's') && (i = 2) != 0))
	{
		char_star_format(ap, *(str + 0), mai);
	}
	return (i);
}
