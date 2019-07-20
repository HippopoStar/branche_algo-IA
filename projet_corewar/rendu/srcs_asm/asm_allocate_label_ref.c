/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_allocate_label_ref.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:26:35 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/11 06:22:10 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

/*
** Au moment du parsing, avant d'appeler 'asm_allocate_label_ref',
** il faut temporairement remplacer le caractere suivant la declaration
** du label par un '\0'
**
** Anciennement :
**		(*node)->op_code_pos = (data->surrent_inst)->op_code_pos;
**		(*node)->ref_pos = data->output_index;
*/

static void	aux_asm_allocate_label_ref(t_lab_ref **node, char *label_name)
{
	if (!(((*node) = (t_lab_ref *)malloc(sizeof(t_lab_ref))) == NULL))
	{
		(*node)->label_name = ft_strdup(label_name);
		(*node)->next = NULL;
	}
}

int			asm_allocate_label_ref(t_asm_data *data, char *label_name,\
														size_t pos, size_t size)
{
	t_lab_ref	**node;

	node = &(data->label_refs);
	while (!((*node) == NULL))
	{
		node = &((*node)->next);
	}
	aux_asm_allocate_label_ref(node, label_name);
	if (!((*node) == NULL))
	{
		(*node)->op_code_pos = (data->current_inst)->op_code_pos;
		(*node)->ref_pos = pos;
		(*node)->size = size;
	}
	return (!((*node) == NULL || (*node)->label_name == NULL)
			? 1
			: asm_memory_allocation_fail());
}
