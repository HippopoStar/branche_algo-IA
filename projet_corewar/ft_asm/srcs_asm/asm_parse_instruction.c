/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_instruction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:29:23 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/08 17:29:25 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

/*
** (char *)(data->current_inst)->prog est initialisee dans 'asm_parse_prog'
** (char)(data->current_inst)->op_code est initialisee dans 'asm_get_inst_op_code'
** (int)(data->current_inst)->nb_of_args est initialisee dans 'asm_op_code_one/two/three/four'
*/

static void	asm_initialize_inst_struct(t_asm_data *data, size_t pos)
{
	(data->current_inst)->op_code_pos = pos;
	(data->current_inst)->checksum = '\0';
}

/*
** On transmet a 'asm_parse_inst_arg' l'adresse de la copie de 'i'
**
**	ft_putstr("ams_parse_instruction\n");
**	ft_putstr(&(*(line + i)));
**	ft_putchar('\n');
**			asm_putchar_prog((data->current_inst)->prog, pos, (data->current_inst)->op_code);
*/

int		asm_parse_instruction(t_asm_data *data, char *line, size_t i, size_t *pos)
{
	size_t	arg_nb;

	if (!(*(line + i) == '\0' || *(line + i) == COMMENT_CHAR))
	{
		asm_initialize_inst_struct(data, *pos);
		if (asm_get_inst_op_code(data->current_inst, line, &i))
		{
			arg_nb = 0;
			while (arg_nb < (data->current_inst)->nb_of_args
					&& asm_parse_inst_arg(data, line, &i, arg_nb))
			{
				arg_nb++;
			}
			if (arg_nb == (data->current_inst)->nb_of_args
					&& asm_check_inst_args(data->current_inst)
					&& asm_put_inst_prog(data->current_inst, pos))
			{
				return (1);
			}
		}
		return (0);
	}
	return (1);
}
