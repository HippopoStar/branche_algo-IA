/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_inst_arg_types.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:28:19 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/08 17:28:21 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

/*
**	ft_putstr("'asm_int_arg_types' : ");
**	ft_putstr(&(*(line + (*i))));
**	ft_putchar('\n');
*/

int		asm_inst_arg_type_register(char *line, size_t *i)
{
	if (*(line + (*i)) == 'r' && ft_isdigit(*(line + (*i) + 1)))
	{
		*i = (*i) + 1;
		return (1);
	}
	else
	{
		return (0);
	}
}

int		asm_inst_arg_type_direct(char *line, size_t *i)
{
	if (*(line + (*i)) == DIRECT_CHAR)
	{
		if (*(line + (*i) + 1) == '+' || *(line + (*i) + 1) == '-')
		{
			if (ft_isdigit(*(line + (*i) + 2)))
			{
				*i = (*i) + 1;
				return (1);
			}
		}
		else if (ft_isdigit(*(line + (*i) + 1)))
		{
			*i = (*i) + 1;
			return (1);
		}
	}
	return (0);
}

int		asm_inst_arg_type_indirect(char *line, size_t *i)
{
	if (*(line + (*i)) == '+' || *(line + (*i)) == '-')
	{
		if (ft_isdigit(*(line + (*i) + 1)))
		{
			return (1);
		}
	}
	else if (ft_isdigit(*(line + (*i))))
	{
		return (1);
	}
	return (0);
}

int		asm_inst_arg_type_label(char *line, size_t *i)
{
	if (*(line + (*i)) == DIRECT_CHAR
			&& *(line + (*i) + 1) == LABEL_CHAR
			&& ft_strchr(LABEL_CHARS, (int)*(line + (*i) + 2)))
	{
		*i = (*i) + 2;
		return (1);
	}
	else
	{
		return (0);
	}
}
