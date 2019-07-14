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

static int	asm_allocate_lab_dec(t_asm_data *data, char *label_name, size_t pos)
{
	t_lab_dec	**tmp;

	tmp = &(*(data->label_tab + pos));
	while (!((*tmp) == NULL))
	{
		tmp = &((*tmp)->next);
	}
	if (!((*tmp) = (t_lab_dec *)malloc(sizeof(t_lab_dec)))
			|| !((*tmp)->label_name = ft_strdup(label_name)))
	{
		return (0);
	}
	else
	{
		(*tmp)->next = NULL;
		return (1);
	}
}

static int	aux_asm_label_declaration_available(t_asm_data *data, size_t i,\
															char *label_name)
{
	t_lab_dec	*tmp;

	tmp = *(data->label_tab + i);
	while (!(tmp == NULL || tmp->label_name == NULL))
	{
		if (!ft_strcmp(tmp->label_name, label_name))
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

/*
** A present, la fonction 'asm_label_declaration_available' renvoie toujours '1'
** mais leve des 'Warning' dans certains cas
*/

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
						&& !aux_asm_label_declaration_available(data, i, \
							label_name))
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
	if (*(line + (*i) + j) == LABEL_CHAR && !(*(line + (*i) + j) = '\0'))
	{
		if (asm_label_declaration_available(data, &(*(line + (*i))), pos)
				|| !(*(line + (*i) + j) = LABEL_CHAR))
		{
			if ((asm_allocate_lab_dec(data, &(*(line + (*i))), pos)
						&& (*(line + (*i) + j) = LABEL_CHAR))
					|| !(*(line + (*i) + j) = LABEL_CHAR))
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
