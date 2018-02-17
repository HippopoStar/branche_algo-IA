/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_padding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:01:39 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/17 22:01:42 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Remarque : les flag '0' ne peut pas etre combine a une indication de largeur
**            minimale de champ
*/

void	p_sharp_mark(char c, t_pf *mai)
{
	size_t	i;

	i = 0;
	while (*(mai->str + i) == ' ' || *(mai->str + i) == '0')
		i++;
	if (occurs(c, "oxXO") && i != ft_strlen(mai->str))
	{
		if (i == 0)
		{
			if (c == 'o' || c == 'O')
				insert_a_string_in_another("0", mai, i);
			else if (c == 'x')
				insert_a_string_in_another("0x", mai, i);
			else
				insert_a_string_in_another("0X", mai, i);
		}
		else if (i == 1)
		{
			*(mai->str + 0) = (occurs(c, "xX") ? c : '0');
			if (occurs(c, "xX"))
				insert_a_string_in_another("0", mai, 0);
		}
		else
		{
			if (occurs(c, "xX") && !(strncmp(mai->str + 0, "00", 2)))
				*(mai->str + 1) = c;
			else
			{
				i = 0;
				while (*(mai->str + i) == ' ')
					i++;
				*(mai->str + i - 1) = (occurs(c, "xX") ? c : '0');
				*(mai->str + i - 2) = (occurs(c, "xX") ? '0' : ' ');
			}
		}
	}
}

size_t	aux_p_padding(char *str, char *minus_sign)
{
	size_t	retour;
	size_t	i;

	if ((retour = find_flag('-', str)) > 0)
	{
		*minus_sign = '-';
		if (retour != 1)
		{
			return (retour);
		}
		else
		{
			i = 0;
			while (*(str + i) != '-')
			{
				i++;
			}
			return ((ft_atoi(str + i + 1) == 1) ? 1 : field_width_length(str));
		}
	}
	else
	{
		return (field_width_length(str));
	}
}

void	p_padding(size_t retour, t_pf *mai, char minus_sign)
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
		(minus_sign == '-') ?
		insert_a_string_in_another(blanks, mai, size)
		: insert_a_string_in_another(blanks, mai, 0);
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
	if (*(mai->str + i) == '0')
	{
		*(mai->str + i) = '+';
	}
	else if (*(mai->str + i) != '-')
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
	size_t	i;

	i = 0;
	while (!(occurs(*(mai->str + i), "-0123456789")))
	{
		i++;
	}
	if (*(mai->str + i) == '0')
	{
		*(mai->str + i) = ' ';
	}
	else if (*(mai->str + i) != '-')
	{
		if (i > 0 && *(mai->str + i - 1) != ' ')
		{
			insert_a_string_in_another(" ", mai, i - 1);
		}
		else
		{
			insert_a_string_in_another(" ", mai, 0);
		}
	}
}
