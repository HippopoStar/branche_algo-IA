/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_unicode_string_mai.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 01:34:44 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/13 04:57:03 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	aux_ausm(wchar_t *uni_string, size_t i, t_pf *mai)
{
	char	char_array[(i * 4) + 1];
	char	unicode_char[5];
	size_t	nb_of_char;
	size_t	j;

	nb_of_char = 0;
	j = 0;
	while (*(uni_string + j) != '\0')
	{
		take_up_unicode_char((wint_t)(*(uni_string + j)), unicode_char);
		ft_strcpy((char_array + nb_of_char), unicode_char);
		nb_of_char = nb_of_char + ft_strlen(unicode_char);
		j++;
	}
	*(char_array + nb_of_char) = '\0';
	add_str_mai(char_array, -1, mai);
}

void	add_unicode_string_mai(va_list ap, t_pf *mai)
{
	wchar_t	*uni_string;
	size_t	i;

	uni_string = va_arg(ap, wchar_t *);
	i = 0;
	while (*(uni_string + i) != '\0')
	{
		i++;
	}
	aux_ausm(uni_string, i, mai);
}
