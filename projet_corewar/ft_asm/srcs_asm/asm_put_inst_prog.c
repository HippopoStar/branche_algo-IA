/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_put_inst_prog.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:30:26 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/08 17:30:28 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

static int	asm_put_checksum_prog(t_asm_inst *inst, size_t *pos)
{
	size_t	i;

	inst->checksum = '\0';
	i = 0;
	while (i < inst->nb_of_args)
	{
		inst->checksum = inst->checksum + ((inst->arg + i)->check << (6 - (i * 2)));
		i++;
	}
	if (asm_putchar_prog(inst->prog, pos, inst->checksum))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*
** La variable 'inst->checksum' est soit initialisee a '\0'
** dans le fichier 'asm_parse_instruction.c',
** soit a '(char)1' dans le fichier 'asm_get_inst_op_code.c'
*/

static int	asm_put_op_code_checksum_prog(t_asm_inst *inst, size_t *pos)
{
	if (asm_putchar_prog(inst->prog, pos, inst->op_code))
	{
		if (inst->checksum == '\0')
		{
			return (1);
		}
		else
		{
			return (asm_put_checksum_prog(inst, pos));
		}
	}
	else
	{
		return (0);
	}
}

static int	asm_put_arg_prog(t_asm_arg *arg, char *prog, size_t *pos)
{
	if (arg->size == 1 && asm_putchar_prog(prog, pos, (char)arg->value))
	{
		return (1);
	}
	else if (arg->size == 2 && asm_putusint_prog(prog, pos, (unsigned short int)arg->value))
	{
		return (1);
	}
	else if (arg->size == 4 && asm_putuint_prog(prog, pos, (unsigned int)arg->value))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		asm_put_inst_prog(t_asm_inst *inst, size_t *pos)
{
	size_t	i;

	if (asm_put_op_code_checksum_prog(inst, pos))
	{
		i = 0;
		while (i < inst->nb_of_args)
		{
			if (!asm_put_arg_prog(inst->arg + i, inst->prog, pos))
			{
				return (0);
			}
			i++;
		}
		return (1);
	}
	else
	{
		return (0);
	}
}
