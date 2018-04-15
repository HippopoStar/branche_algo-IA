/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_padding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:01:39 by lcabanes          #+#    #+#             */
/*   Updated: 2018/04/15 17:51:12 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Remarque : les flag '0' ne peut pas etre combine a une indication de largeur
**            minimale de champ
** Idee :     utiliser " i - (occurs(c, "xX") ? 2 : 1) "
*/

void	pf_p_sharp_mark(char c, t_pf *mai)
{
	size_t	i;

	i = 0;
	while (*(mai->str + i) == ' ' || *(mai->str + i) == '0')
		i++;
	if (pf_occurs(c, "oxXO") && i != ft_strlen(mai->str))
	{
		if (i == 0)
		{
			if (c == 'o' || c == 'O')
				pf_insert_a_string_in_another("0", mai, i);
			else if (c == 'x')
				pf_insert_a_string_in_another("0x", mai, i);
			else
				pf_insert_a_string_in_another("0X", mai, i);
		}
		else if (i == 1)
		{
			*(mai->str + 0) = (pf_occurs(c, "xX") ? c : '0');
			if (pf_occurs(c, "xX"))
				pf_insert_a_string_in_another("0", mai, 0);
		}
		else
		{
			if (pf_occurs(c, "xX") && !(ft_strncmp(mai->str, "00", 2)))
				*(mai->str + 1) = c;
			else
			{
				*(mai->str + i - 1) = (pf_occurs(c, "xX") ? c : '0');
				*(mai->str + i - 2) = (pf_occurs(c, "xX") ?
						'0' : *(mai->str + i - 2));
			}
		}
	}
}

ssize_t	pf_aux_p_padding(char *str, char *minus_sign)
{
	ssize_t	retour;
	size_t	i;

	if ((retour = pf_find_flag('-', str)) >= 0)
	{
		*minus_sign = '-';
		if (retour > 0)
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
			return ((ft_atoi(str + i + 1) == 0 && *(str + i + 1) == '0') ?
					0 : pf_field_width_length(str));
		}
	}
	else
	{
		return (pf_field_width_length(str));
	}
}

/*
** NOTE :
** L'emploi de 'variable_length_array' est proscrite par la Norme
** (dans la declaration de variable 'blanks[retour + 1]')
*/

void	pf_p_padding(size_t retour, t_pf *mai, char minus_sign)
{
	char	*blanks;
	size_t	size;
	size_t	i;

	if (!(blanks = (char *)malloc((retour + 1) * sizeof(char))))
		pf_error_code("Erreur dans \"ft_printf\"");
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
		pf_insert_a_string_in_another(blanks, mai, size)
		: pf_insert_a_string_in_another(blanks, mai, 0);
	}
	free(blanks);
}

void	pf_p_plus_sign(t_pf *mai)
{
	size_t	i;

	i = 0;
	while (!(pf_occurs(*(mai->str + i), "-0123456789")))
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
			pf_insert_a_string_in_another("+", mai, i);
		}
	}
}

void	pf_p_space(t_pf *mai)
{
	size_t	i;

	i = 0;
	while (!(pf_occurs(*(mai->str + i), "-0123456789")))
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
			pf_insert_a_string_in_another(" ", mai, i - 1);
		}
		else
		{
			pf_insert_a_string_in_another(" ", mai, 0);
		}
	}
}
