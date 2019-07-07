#include "ft_asm.h"

/*
**	ft_putstr(&(*(line + (*i))));
**	ft_putstr("\n'inst->nb_of_args' : ");
**	ft_putnbr(inst->nb_of_args);
**	ft_putstr("\n'arg_nb' : ");
**	ft_putnbr(arg_nb);
**	ft_putchar('\n');
*/

static int	asm_inst_arg_fits(t_asm_inst *inst, char *line, size_t *i, size_t arg_nb)
{
	ft_putstr(&(*(line + (*i))));
	ft_putstr("\n'inst->nb_of_args' : ");
	ft_putnbr(inst->nb_of_args);
	ft_putstr("\n'arg_nb' : ");
	ft_putnbr(arg_nb);
	ft_putchar('\n');
	if (inst->nb_of_args > 0)
	{
		if (arg_nb < inst->nb_of_args - 1)
		{
			if (*(line + (*i)) == SEPARATOR_CHAR)
			{
				ft_putstr("Cas 1\n");
				(*i)++;
				asm_skip_spacing_chars(line, i);
				return (1);
			}
			ft_putstr("Cas 2\n");
		}
		else if (*(line + (*i)) == '\0' || *(line + (*i)) == COMMENT_CHAR)
		{
			ft_putstr("Cas 3\n");
			return (1);
		}
		ft_putstr("Cas 4\n");
	}
	ft_putstr("Cas 5\n");
	return (0);
}

/*
** Note :
** Quelque soit l'instruction, on a (int)inst->nb_of_args > 0
**
**	ft_putstr("asm_parse_inst_arg\n");
**	ft_putstr(&(*(line + (*i))));
**	ft_putchar('\n');
*/

int		asm_parse_inst_arg(t_asm_data *data, char *line, size_t *i, size_t arg_nb)
{
	int		ret_val;

	ft_putstr("asm_parse_inst_arg\n");
	ft_putstr(&(*(line + (*i))));
	ft_putchar('\n');
	ret_val = 0;
	if (asm_inst_arg_type_register(line, i))
	{
		ret_val = asm_parse_arg_register(data, line, i, arg_nb);
	}
	else if (asm_inst_arg_type_direct(line, i))
	{
		ret_val = asm_parse_arg_direct(data, line, i, arg_nb);
	}
	else if (asm_inst_arg_type_indirect(line, i))
	{
		ret_val = asm_parse_arg_indirect(data, line, i, arg_nb);
	}
	else if (asm_inst_arg_type_label(line, i))
	{
		ret_val = asm_parse_arg_label(data, line, i, arg_nb);
	}
	if (ret_val)
	{
		ft_putstr("WOHLA !\n");
		asm_skip_spacing_chars(line, i);
		return (ret_val && asm_inst_arg_fits(data->current_inst, line, i, arg_nb) ? 1 : 0);
	}
	return (0);
}
