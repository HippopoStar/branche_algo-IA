/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_unicode_string_mai.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 01:34:44 by lcabanes          #+#    #+#             */
/*   Updated: 2018/04/15 17:49:16 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** NOTE :
** L'emploie de 'variable_length_array' est proscrite par la Norme
** (dans la declaration de variable 'char_array[(i * 4) + 1]')
*/

void	pf_aux_ausm(wchar_t *uni_string, size_t i, t_pf *mai)
{
	char	*char_array;
	char	unicode_char[5];
	size_t	nb_of_char;
	size_t	j;

	if (!(char_array = (char *)malloc(((i * 4) + 1) * sizeof(char))))
		pf_error_code("Erreur dans \"ft_printf\"");
	nb_of_char = 0;
	j = 0;
	while (*(uni_string + j) != '\0')
	{
		pf_take_up_unicode_char((wint_t)(*(uni_string + j)), unicode_char);
		ft_strcpy((char_array + nb_of_char), unicode_char);
		nb_of_char = nb_of_char + ft_strlen(unicode_char);
		j++;
	}
	*(char_array + nb_of_char) = '\0';
	pf_add_str_mai(char_array, -1, mai);
	free(char_array);
}

void	pf_add_unicode_string_mai(va_list ap, t_pf *mai)
{
	wchar_t	*uni_string;
	size_t	i;

	uni_string = va_arg(ap, wchar_t *);
	i = 0;
	while (*(uni_string + i) != '\0')
	{
		i++;
	}
	pf_aux_ausm(uni_string, i, mai);
	mai->len = i;
}
