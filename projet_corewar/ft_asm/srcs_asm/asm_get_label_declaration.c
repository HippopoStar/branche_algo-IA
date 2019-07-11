/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_label_declaration.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:27:55 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/11 02:48:55 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

static int	asm_label_declaration_available(t_asm_data *data, char *label_name,\
																	size_t pos)
{
	size_t	i;

	if (*(data->label_tab + pos) == NULL)
	{
		if (pos > 0)
		{
			i = 0;
			while (i < pos)
			{
				if (!(*(data->label_tab + i) == NULL) \
						&& !ft_strcmp(*(data->label_tab + i), label_name))
				{
					return (asm_label_name_already_exists(label_name));
				}
				i++;
			}
		}
	}
	else
	{
		return (asm_two_labels_in_a_row(data));
	}
	return (1);
}

/*
** Retrait ostentatoire d'accolades pour flatter la Norme
** (voir https://meta.intra.42.fr/articles/norm-norminette)
**
**	ft_putstr("get_label_declaration\n");
*/

int			asm_get_label_declaration(t_asm_data *data, char *line, size_t *i,\
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
		if (asm_label_declaration_available(data, &(*(line + (*i))), pos))
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
			return (0);
	}
	return (1);
}
