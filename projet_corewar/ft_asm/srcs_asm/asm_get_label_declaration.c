/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_label_declaration.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:27:55 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/08 18:45:47 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

/*
** Retrait ostentatoire d'accolades pour flatter la Norme
** (voir https://meta.intra.42.fr/articles/norm-norminette)
**
**	ft_putstr("get_label_declaration\n");
*/

int		asm_get_label_declaration(t_asm_data *data, char *line, size_t *i,\
																	size_t pos)
{
	size_t	j;

	j = 0;
	while (!(*(line + (*i) + j) == '\0')\
							&& ft_strchr(LABEL_CHARS, (int)*(line + (*i) + j)))
		j++;
	if (*(line + (*i) + j) == LABEL_CHAR)
	{
		*(line + (*i) + j) = '\0';
		if (*(data->label_tab + pos) == NULL)
		{
			if (!((*(data->label_tab + pos) = ft_strdup(&(*(line + (*i)))))\
						== NULL))
			{
				*i = (*i) + j + 1;
				asm_skip_spacing_chars(line, i);
			}
			else
				return (asm_memory_allocation_fail());
		}
		else
			return (asm_two_labels_in_a_row(data));
	}
	return (1);
}
