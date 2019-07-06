#include "ft_asm.h"

static int	aux_asm_check_labels(t_asm_data *data, t_lab_ref *label_ref, char *prog)
{
	unsigned short int	indirect;
	size_t		i;

	i = 0;
	while (i < CHAMP_MAX_SIZE && (*(data->label_tab + i) == NULL
			|| ft_strcmp(label_ref->label_name, *(data->label_tab + i))))
	{
		i++;
	}
	if (i < CHAMP_MAX_SIZE)
	{
		indirect = (unsigned short int)(i - label_ref->op_code_pos);
		if (asm_putuint_prog(prog, &(label_ref->ref_pos), indirect))
		{
			return (1);
		}
	}
	return (asm_inexisting_label_reference(label_ref->label_name));
}

static int	asm_check_labels(t_asm_data *data, char *prog)
{
	t_lab_ref		*tmp;

	tmp = data->label_refs;
	while (!(tmp == NULL))
	{
		if (!aux_asm_check_labels(data, tmp, prog))
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

/*
** Rappel :
** (char *)prog est un tableau de char de dimension CHAMP_MAX_SIZE
**
**	ft_putstr("asm_parse_prog\n");
*/

int		asm_parse_prog(t_asm_data *data, t_header *h, char **line, char *prog)
{
	int		ret_gnl;
	t_asm_inst	inst;
	size_t	pos;

	ft_putstr("asm_parse_prog\n");
	h->prog_size = 23;
	pos = 0;
	inst.op_code_pos = 0;
	data->current_inst = &inst;
	while ((ret_gnl = asm_parse_line(data, line, &pos)) == 1)
		;
	if (ret_gnl == 0)
	{
		asm_check_labels(data, prog);
		return (1);
	}
	else
	{
		return (0);
	}
}
