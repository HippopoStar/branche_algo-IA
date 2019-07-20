/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_inst_op_code.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:27:40 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/08 18:01:01 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

static char	asm_op_code_one(t_asm_inst *inst, char *line, size_t *i)
{
	if (!ft_strncmp(&(*(line + (*i))), "live", 4))
	{
		inst->nb_of_args = 1;
		*i = (*i) + 5;
		return ((char)1);
	}
	else if (!ft_strncmp(&(*(line + (*i))), "ld", 2))
	{
		inst->nb_of_args = 2;
		*i = (*i) + 3;
		return ((char)2);
	}
	else if (!ft_strncmp(&(*(line + (*i))), "st", 2))
	{
		inst->nb_of_args = 2;
		*i = (*i) + 3;
		return ((char)3);
	}
	else if (!ft_strncmp(&(*(line + (*i))), "add", 3))
	{
		inst->nb_of_args = 3;
		*i = (*i) + 4;
		return ((char)4);
	}
	return ('\0');
}

static char	asm_op_code_two(t_asm_inst *inst, char *line, size_t *i)
{
	if (!ft_strncmp(&(*(line + (*i))), "sub", 3))
	{
		inst->nb_of_args = 3;
		*i = (*i) + 4;
		return ((char)5);
	}
	else if (!ft_strncmp(&(*(line + (*i))), "and", 3))
	{
		inst->nb_of_args = 3;
		*i = (*i) + 4;
		return ((char)6);
	}
	else if (!ft_strncmp(&(*(line + (*i))), "or", 2))
	{
		inst->nb_of_args = 3;
		*i = (*i) + 3;
		return ((char)7);
	}
	else if (!ft_strncmp(&(*(line + (*i))), "xor", 3))
	{
		inst->nb_of_args = 3;
		*i = (*i) + 4;
		return ((char)8);
	}
	return ('\0');
}

static char	asm_op_code_three(t_asm_inst *inst, char *line, size_t *i)
{
	if (!ft_strncmp(&(*(line + (*i))), "zjmp", 4))
	{
		inst->nb_of_args = 1;
		*i = (*i) + 5;
		return ((char)9);
	}
	else if (!ft_strncmp(&(*(line + (*i))), "ldi", 3))
	{
		inst->nb_of_args = 3;
		*i = (*i) + 4;
		return ((char)10);
	}
	else if (!ft_strncmp(&(*(line + (*i))), "sti", 3))
	{
		inst->nb_of_args = 3;
		*i = (*i) + 4;
		return ((char)11);
	}
	else if (!ft_strncmp(&(*(line + (*i))), "fork", 4))
	{
		inst->nb_of_args = 1;
		*i = (*i) + 5;
		return ((char)12);
	}
	return ('\0');
}

/*
** On a remplace l'ordre des conditions pour verifier
** 'lldi' avant 'lld'
*/

static char	asm_op_code_four(t_asm_inst *inst, char *line, size_t *i)
{
	if (!ft_strncmp(&(*(line + (*i))), "lldi", 4))
	{
		inst->nb_of_args = 3;
		*i = (*i) + 5;
		return ((char)14);
	}
	else if (!ft_strncmp(&(*(line + (*i))), "lld", 3))
	{
		inst->nb_of_args = 2;
		*i = (*i) + 4;
		return ((char)13);
	}
	else if (!ft_strncmp(&(*(line + (*i))), "lfork", 5))
	{
		inst->nb_of_args = 1;
		*i = (*i) + 6;
		return ((char)15);
	}
	else if (!ft_strncmp(&(*(line + (*i))), "aff", 3))
	{
		inst->nb_of_args = 1;
		*i = (*i) + 4;
		return ((char)16);
	}
	return ('\0');
}

/*
** La viariable 'inst->checksum' est prealablement initialisee a '\0'
** dans le fichier 'asm_parse_instruction.c'
**
** On a remplace l'ordre d'appel des fonctions auxiliaires car
** 'sti' et 'ldi' sont dans 'asm_op_code_three',
** 'st' et 'ld' sont dans 'asm_op_code_one'
*/

int			asm_get_inst_op_code(t_asm_inst *inst, char *line, size_t *i)
{
	if ((inst->op_code = asm_op_code_four(inst, line, i))
			|| (inst->op_code = asm_op_code_three(inst, line, i))
			|| (inst->op_code = asm_op_code_two(inst, line, i))
			|| (inst->op_code = asm_op_code_one(inst, line, i)))
	{
		if (!(*(line + (*i)) == '\0' || *(line + (*i)) == COMMENT_CHAR))
		{
			if (!(inst->op_code == (char)1
					|| inst->op_code == (char)9
					|| inst->op_code == (char)12
					|| inst->op_code == (char)15))
			{
				inst->checksum = (char)1;
			}
			asm_skip_spacing_chars(line, i);
			return (1);
		}
	}
	return (0);
}
