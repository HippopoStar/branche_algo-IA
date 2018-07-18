/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 01:28:30 by lcabanes          #+#    #+#             */
/*   Updated: 2018/04/17 01:27:22 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_add_char_mai(char c, t_pf *mai)
{
	if (!(mai->str = (char *)malloc(2 * sizeof(char))))
		pf_error_code("Erreur dans \"add_elem.c\\add_char_mai\"");
	mai->len = 1;
	*(mai->str + 0) = c;
	*(mai->str + 1) = '\0';
}

/*
** /!\ 'add_str_mai' ne remplit pas la donnee 'mai->len'
*/

void	pf_add_str_mai(char *str, ssize_t p_length, t_pf *mai)
{
	size_t	length;
	size_t	i;

	length = ((p_length < 0) ? ft_strlen(str) : (size_t)p_length);
	if (!(mai->str = (char *)malloc((length + 1) * sizeof(char))))
		pf_error_code("Erreur dans \"add_elem.c\\add_str_mai\"");
	*(mai->str + length) = '\0';
	i = 0;
	while (i < length)
	{
		*(mai->str + i) = *(str + i);
		i++;
	}
}
