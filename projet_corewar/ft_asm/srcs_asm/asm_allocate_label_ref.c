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

static void	aux_asm_allocate_label_ref(t_asm_data *data, char *label_name, t_lab_ref **node, size_t i)
{
	if (!(((*node) = (t_lab_ref *)malloc(sizeof(t_lab_ref))) == NULL))
	{
		(*node)->label_name = ft_strdup(label_name);
		(*node)->op_code_pos = (data->current_inst)->op_code_pos;
		(*node)->ref_pos = i;
		(*node)->next = NULL;
	}
}

int		asm_allocate_label_ref(t_asm_data *data, char *label_name, size_t i)
{
	t_lab_ref	**node;

	node = &(data->label_refs);
	while (!((*node) == NULL))
	{
		node = &((*node)->next);
	}
	aux_asm_allocate_label_ref(data, label_name, node, i);
	return (!((*node) == NULL || (*node)->label_name == NULL) ? 1 : 0);
}
