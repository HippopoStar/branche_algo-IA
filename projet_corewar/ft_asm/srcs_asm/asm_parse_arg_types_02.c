/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_arg_types_02.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:50:11 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/11 02:46:25 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

/*
** A ce moment la du parsing, on a determine qu'on avait affaire a un label
** %:label -> direct (3)
** :label -> indirect (2)
*/

static void		asm_parse_arg_label_get_type(t_asm_data *data, char *line,\
													size_t *i, size_t arg_nb)
{
	if (*(line + (*i)) == DIRECT_CHAR && *(line + (*i) + 1) == LABEL_CHAR)
	{
		((data->current_inst)->arg + arg_nb)->check = (char)2;
		*i = (*i) + 2;
	}
	else if (*(line + (*i)) == LABEL_CHAR)
	{
		((data->current_inst)->arg + arg_nb)->check = (char)3;
		*i = (*i) + 1;
	}
}

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
** On avance que de '1' caractere dans la chaine dans la fonction
** 'asm_parse_inst_arg_label' appelee prealablement dans 'asm_parse_inst_arg',
** afin d'avoir connaissance de la nature directe ou indirect de l'argument
** dans 'asm_parse_arg_label'
**
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

	asm_parse_arg_label_get_type(data, line, i, arg_nb);
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
