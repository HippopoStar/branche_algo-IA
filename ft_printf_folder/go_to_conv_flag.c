/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_conv_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 18:21:22 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/16 19:48:23 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** La fonction "skip_leng_modi_and_conv_spec_for_integers" renvoie une valeur
** non nulle seulement si le "conversion specifier" designe un "integer"
** non obsolete
*/

size_t	skip_leng_modi_and_conv_spec_for_integers(char *str)
{
	size_t	i;

	i = 0;
	if (!(strncmp(str, "hh", 2)) || !(strncmp(str, "ll", 2)))
	{
		i = 2;
	}
	else if (occurs(*(str + 0), "hljz"))
	{
		i = 1;
	}
	if (occurs(*(str + i), "diouxX"))
	{
		return (i + 1);
	}
	else
	{
		return (0);
	}
}

size_t	skip_length_modifiers(char *str)
{
	size_t	i;

	i = 0;
	while (occurs(*(str + i), LENGTH_MODIFIERS))
	{
		i++;
	}
	return (i);
}

size_t	skip_padding(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0' && !(occurs(*(str + i), LENGTH_MODIFIERS)
		|| occurs(*(str + i), CONVERSION_SPECIFIERS)))
	{
		if (!(occurs(*(str + i), OPTIONNAL_FLAGS)
				|| occurs(*(str + i), "123456789")))
		{
			error_code("Erreur dans \"ft_printf\"");
		}
		i++;
	}
	return (i);
}

size_t	go_to_conv_flags(char *str)
{
	size_t	i;

	i = 0;
	i = i + skip_padding(str + i);
	i = i + skip_length_modifiers(str + i);
	return (i);
}
