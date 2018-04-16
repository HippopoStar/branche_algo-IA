/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_conv_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 18:21:22 by lcabanes          #+#    #+#             */
/*   Updated: 2018/04/17 01:50:55 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** La fonction "skip_leng_modi_and_conv_spec_for_integers" renvoie une valeur
** non nulle seulement si le "conversion specifier" designe un "integer"
** non obsolete
*/

size_t	pf_skip_leng_modi_and_conv_spec_for_integers(char *str)
{
	size_t	i;

	i = 0;
	if (!(ft_strncmp(str, "hh", 2)) || !(ft_strncmp(str, "ll", 2)))
	{
		i = 2;
	}
	else if (pf_occurs(*(str + 0), "hljz"))
	{
		i = 1;
	}
	if (pf_occurs(*(str + i), "diouxXp"))
	{
		return (i + 1);
	}
	else
	{
		return (0);
	}
}

size_t	pf_skip_length_modifiers(char *str)
{
	size_t	i;

	i = 0;
	while (pf_occurs(*(str + i), LENGTH_MODIFIERS))
	{
		i++;
	}
	return (i);
}

size_t	pf_skip_padding(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0' && !(pf_occurs(*(str + i), LENGTH_MODIFIERS)
		|| pf_occurs(*(str + i), CONVERSION_SPECIFIERS)))
	{
		if (!(pf_occurs(*(str + i), OPTIONNAL_FLAGS)
				|| pf_occurs(*(str + i), "123456789")))
		{
			pf_error_code("Erreur dans \"go_to_conv_flag.c\\skip_padding\"");
		}
		i++;
	}
	return (i);
}

size_t	pf_go_to_conv_flags(char *str)
{
	size_t	i;

	i = 0;
	i = i + pf_skip_padding(str + i);
	i = i + pf_skip_length_modifiers(str + i);
	return (i);
}
