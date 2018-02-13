/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 05:36:17 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/13 10:11:06 by lcabanes         ###   ########.fr       */
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

void	p_minus_sign(size_t retour, t_pf *mai)
{
	char	blanks[retour + 1];
	size_t	size;
	size_t	i;

	size = ft_strlen(mai->str);
	if (retour > size)
	{
		i = 0;
		while (i < retour - size)
		{
			blanks[i] = ' ';
			i++;
		}
		blanks[retour - size] = '\0';
		insert_a_string_in_another(blanks, mai, size);
	}
}

void	p_plus_sign(t_pf *mai)
{
	size_t	i;

	i = 0;
	while (!(occurs(*(mai->str + i), "-0123456789")))
	{
		i++;
	}
	if (*(mai->str + i) != '-')
	{
		if (i > 0 && *(mai->str + i - 1) == ' ')
		{
			*(mai->str + i - 1) = '+';
		}
		else
		{
			insert_a_string_in_another("+", mai, i);
		}
	}
}

void	p_space(t_pf *mai)
{
	(void)mai;
}

void	p_point(size_t retour, t_pf *mai)
{
	(void)retour;
	(void)mai;
}
