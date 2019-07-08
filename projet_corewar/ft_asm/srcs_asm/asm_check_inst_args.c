#include "ft_asm.h"

/*
**	ft_putstr("'asm_check_register'\n");
*/

static int	asm_check_register(char op_code, size_t i)
{
	ft_putstr("'asm_check_register'\n");
	if (i == 0 && (op_code == (char)3 || op_code == (char)4
				|| op_code == (char)5 || op_code == (char)6
				|| op_code == (char)7 || op_code == (char)8
				|| op_code == (char)10 || op_code == (char)11
				|| op_code == (char)14 || op_code == (char)16))
	{
		return (1);
	}
	else if (i == 1 && (op_code == (char)2 || op_code == (char)3
				|| op_code == (char)4 || op_code == (char)6
				|| op_code == (char)7 || op_code == (char)8
				|| op_code == (char)10 || op_code == (char)11
				|| op_code == (char)13 || op_code == (char)14))
	{
		return (1);
	}
	else if (i == 2 && (op_code == (char)4 || op_code == (char)5
				|| op_code == (char)4 || op_code == (char)6
				|| op_code == (char)7 || op_code == (char)8
				|| op_code == (char)10 || op_code == (char)11
				|| op_code == (char)14))
	{
		return (1);
	}
	return (0);
}

/*
**	ft_putstr("'asm_check_direct'\n");
*/

static int	asm_check_direct(char op_code, size_t i)
{
	ft_putstr("'asm_check_direct'\n");
	if (i == 0 && (op_code == (char)1 || op_code == (char)2
				|| op_code == (char)6 || op_code == (char)7
				|| op_code == (char)8 || op_code == (char)9
				|| op_code == (char)10 || op_code == (char)12
				|| op_code == (char)13 || op_code == (char)14
				|| op_code == (char)15))
	{
		return (1);
	}
	else if (i == 1 && (op_code == (char)6 || op_code == (char)7
				|| op_code == (char)8 || op_code == (char)10
				|| op_code == (char)11 || op_code == (char)14))
	{
		return (1);
	}
	else if (i == 2 && op_code == (char)11)
	{
		return (1);
	}
	return (0);
}

/*
**	ft_putstr("'asm_check_indirect'\n");
*/

static int	asm_check_indirect(char op_code, size_t i)
{
	ft_putstr("'asm_check_indirect'\n");
	if (i == 0 && (op_code == (char)2 || op_code == (char)6
				|| op_code == (char)7 || op_code == (char)8
				|| op_code == (char)10 || op_code == (char)13
				|| op_code == (char)14))
	{
		return (1);
	}
	else if (i == 1 && (op_code == (char)3 || op_code == (char)6
				|| op_code == (char)7 || op_code == (char)8
				|| op_code == (char)11))
	{
		return (1);
	}
	return (0);
}

/*
**		ft_putstr("'asm_check_inst_args' : ");
**		ft_putnbr((int)i);
**		ft_putchar('\n');
*/

int		asm_check_inst_args(t_asm_inst *inst)
{
	size_t	i;

	i = 0;
	while (i < inst->nb_of_args)
	{
		ft_putstr("'asm_check_inst_args' : ");
		ft_putnbr((int)i);
		ft_putchar('\n');
		if ((inst->arg + i)->check == (char)1
				&& !asm_check_register(inst->op_code, i))
				return (0);
		else if ((inst->arg + i)->check == (char)2
				&& !asm_check_direct(inst->op_code, i))
				return (0);
		else if ((inst->arg + i)->check == (char)3
				&& !asm_check_indirect(inst->op_code, i))
				return (0);
		i++;
	}
	return (1);
}
