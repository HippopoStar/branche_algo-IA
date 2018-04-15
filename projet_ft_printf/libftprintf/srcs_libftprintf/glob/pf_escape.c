/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 13:52:21 by lcabanes          #+#    #+#             */
/*   Updated: 2018/04/15 14:30:27 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pf_escape(char *str, t_pf *mai)
{
	size_t	i;
	char	c;

	c = *(str + 1);
	i = 0;
	if (c == '\\' && (i = 2))
		pf_add_char_mai('\\', mai);
	else if (c == 't' && (i = 2))
		pf_add_char_mai('\t', mai);
	else if (c == 'n' && (i = 2))
		pf_add_char_mai('\n', mai);
	else if (c == 'v' && (i = 2))
		pf_add_char_mai('\v', mai);
	else if (c == 'f' && (i = 2))
		pf_add_char_mai('\f', mai);
	else if (c == 'r' && (i = 2))
		pf_add_char_mai('\r', mai);
	return (i);
}
