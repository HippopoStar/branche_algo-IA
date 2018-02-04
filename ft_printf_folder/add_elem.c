/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 01:28:30 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/04 05:16:27 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_char_mai(char c, t_pf *mai)
{
	if (!(mai->str = (char *)malloc(2 * sizeof(char))))
		error_code("Erreur d'alloc'");
	mai->len = 1;
	*(mai->str + 0) = c;
	*(mai->str + 1) = '\0';
}

/*
** /!\ 'add_str_mai' ne remplit pas la donnee 'mai->len'
*/

void	add_str_mai(char *str, t_pf *mai)
{
	size_t	length;
	size_t	i;

	length = ft_strlen(str);
	if (!(mai->str = (char *)malloc((length + 1) * sizeof(char))))
		error_code("Erreur d'alloc'");
	*(mai->str + length) = '\0';
	i = 0;
	while (i < length)
	{
		*(mai->str + i) = *(str + i);
		i++;
	}
}
