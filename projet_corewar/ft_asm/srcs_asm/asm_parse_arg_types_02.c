/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_arg_types_02.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:50:11 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/08 18:50:13 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

static size_t	asm_parse_arg_label_get_ref_pos(t_asm_data *data, size_t arg_nb)
{
	size_t	k;
	size_t	ref_pos;

	ref_pos = (data->current_inst)->op_code_pos;
	ref_pos = ref_pos + 1 + (size_t)(data->current_inst)->checksum;
	k = 0;
	while (k < arg_nb)
	{
		ref_pos = ref_pos + ((data->current_inst)->arg + k)->size;
		k++;
	}
	return (ref_pos);
}

/*
**	ft_putstr("Avant 'asm_parse_arg_label' : ");
**	ft_putstr(&(*(line + (*i))));
**	ft_putchar('\n');
**		ft_putstr("Dans 'ft_strchr' : ");
**		ft_putchar(*(line + (*i) + j));
**		ft_putchar('\n');
**		ft_putstr("Apres 'asm_parse_arg_label' : ");
**		ft_putstr(&(*(line + (*i))));
**		ft_putchar('\n');
*/

int				asm_parse_arg_label(t_asm_data *data, char *line, size_t *i,\
																size_t arg_nb)
{
	size_t	j;
	char	c;
	size_t	ref_pos;

	((data->current_inst)->arg + arg_nb)->check = (char)2;
	((data->current_inst)->arg + arg_nb)->size = 2;
	j = 0;
	while (!(*(line + (*i) + j) == '\0')\
			&& ft_strchr(LABEL_CHARS, (int)*(line + (*i) + j)))
	{
		j++;
	}
	c = *(line + (*i) + j);
	*(line + (*i) + j) = '\0';
	ref_pos = asm_parse_arg_label_get_ref_pos(data, arg_nb);
	if (asm_allocate_label_ref(data, &(*(line + (*i))), ref_pos))
	{
		*(line + (*i) + j) = c;
		*i = (*i) + j;
		return (1);
	}
	else
	{
		return (0);
	}
}
