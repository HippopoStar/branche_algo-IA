/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 13:52:21 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/01 14:18:05 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	escape(char *str)
{
	size_t	i;
	char	c;

	c = *(str + 1);
	i = 0;
	if (c == '\\' && (i = 2))
		ft_putchar('\\');
	else if (c == 't' && (i = 2))
		ft_putchar('\t');
	else if (c == 'n' && (i = 2))
		ft_putchar('\n');
	else if (c == 'r' && (i = 2))
		ft_putchar('\r');
	else if (c == 'v' && (i = 2))
		ft_putchar('\v');
	else if (c == 'f' && (i = 2))
		ft_putchar('\f');
	return (i);
}
