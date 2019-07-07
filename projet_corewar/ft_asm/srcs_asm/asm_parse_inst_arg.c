#include "ft_asm.h"

static int	asm_inst_arg_fits(t_asm_inst *inst, char *line, size_t *i, size_t arg_nb)
{
	if (inst->nb_of_args > 0)
	{
		if (arg_nb < inst->nb_of_args - 1)
		{
			if (*(line + (*i)) == SEPARATOR_CHAR)
			{
				(*i)++;
				asm_skip_spacing_chars(line, i);
				return (1);
			}
		}
		else if (*(line + (*i)) == '\0' || *(line + (*i)) == COMMENT_CHAR)
		{
			return (1);
		}
	}
	return (0);
}

/*
** Note :
** Quelque soit l'instruction, on a (int)inst->nb_of_args > 0
**
**	ft_putstr("asm_parse_inst_arg\n");
*/

int		asm_parse_inst_arg(t_asm_inst *inst, char *line, size_t *i, size_t arg_nb)
{
	ft_putstr("asm_parse_inst_arg\n");
	asm_skip_spacing_chars(line, i);
	return (asm_inst_arg_fits(inst, line, i, arg_nb));
}
