/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 05:36:17 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/13 09:09:54 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_sharp_mark(char c, t_pf *mai)
{
	size_t	i;

	i = 0;
	while (!(occurs(*(mai->str + i), "0123456789")))
		i++;
	if (*(mai->str + i) != '0' && occurs(c, "oxX"))
	{
		if (c == 'o')
			insert_a_string_in_another("0", mai, i);
		else if (c == 'x')
			insert_a_string_in_another("0x", mai, i);
		else
			insert_a_string_in_another("0X", mai, i);
	}
}
