/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_arg_types_01.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:49:17 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/08 18:49:42 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

/*
**	ft_putstr("'asm_parse_arg_types' : ");
**	ft_putstr(&(*(line + (*i))));
**	ft_putstr("\n'atoi' return : ");
**	ft_putnbr((int)u);
**	ft_putchar('\n');
*/

int				asm_parse_arg_register(t_asm_data *data, char *line, size_t *i,\
																size_t arg_nb)
{
	unsigned int	u;

	u = (unsigned int)asm_ft_atoi(&(*(line + (*i))));
	((data->current_inst)->arg + arg_nb)->check = (char)1;
	((data->current_inst)->arg + arg_nb)->size = 1;
	if (!(u == 0 || u > 16))
	{
		((data->current_inst)->arg + arg_nb)->value = u;
	}
	else
	{
		return (0);
	}
	while (ft_isdigit(*(line + (*i))))
	{
		(*i)++;
	}
	return (1);
}

static size_t	asm_parse_arg_direct_size(t_asm_data *data)
{
	if ((data->current_inst)->op_code == 9\
			|| (data->current_inst)->op_code == 10\
			|| (data->current_inst)->op_code == 11\
			|| (data->current_inst)->op_code == 12\
			|| (data->current_inst)->op_code == 14\
			|| (data->current_inst)->op_code == 15)
	{
		return (2);
	}
	else
	{
		return (4);
	}
}

/*
** Depuis le decret d'application concernant la Norme
** (voir https://meta.intra.42.fr/articles/norm-norminette)
** la ligne terminant par '= \' est consideree comme remplissant les criteres
**
** grep '= \\\\' ./srcs_asm
*/

int				asm_parse_arg_direct(t_asm_data *data, char *line, size_t *i,\
																size_t arg_nb)
{
	unsigned int	u;

	u = (unsigned int)asm_ft_atoi(&(*(line + (*i))));
	((data->current_inst)->arg + arg_nb)->check = (char)2;
	((data->current_inst)->arg + arg_nb)->size = \
												asm_parse_arg_direct_size(data);
	((data->current_inst)->arg + arg_nb)->value = u;
	if (*(line + (*i)) == '+' || *(line + (*i)) == '-')
	{
		(*i)++;
	}
	while (ft_isdigit(*(line + (*i))))
	{
		(*i)++;
	}
	return (1);
}

int				asm_parse_arg_indirect(t_asm_data *data, char *line, size_t *i,\
																size_t arg_nb)
{
	unsigned int	u;

	u = (unsigned int)asm_ft_atoi(&(*(line + (*i))));
	((data->current_inst)->arg + arg_nb)->check = (char)3;
	((data->current_inst)->arg + arg_nb)->size = 2;
	((data->current_inst)->arg + arg_nb)->value = u;
	if (*(line + (*i)) == '+' || *(line + (*i)) == '-')
	{
		(*i)++;
	}
	while (ft_isdigit(*(line + (*i))))
	{
		(*i)++;
	}
	return (1);
}
