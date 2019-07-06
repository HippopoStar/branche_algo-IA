#include "ft_asm.h"

static int	aux_asm_check_labels(t_asm_data *data, t_label_ref *label_ref, char *prog)
{
	unsigned short int	indirect;
	size_t		i;

	i = 0;
	while (i < CHAMP_MAX_SIZE && (*(data->label_tab + i) == NULL
			|| ft_strcmp(tmp->label_name, *(data->label_tab + i))))
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
	return (0);
}

static int	asm_check_labels(t_asm_data *data, char *prog)
{
	t_label_ref		*tmp;
	unsigned short int	;
	

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
*/

int		asm_parse_prog(t_asm_data *data, char **line, char *prog)
{
	(void)data;
	(void)line;
	(void)prog;
	asm_check_labels(t_asm_data *data, char *prog);
	return (1);
}
