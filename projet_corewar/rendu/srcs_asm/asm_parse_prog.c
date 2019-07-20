/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_prog.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:29:48 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/19 00:11:43 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

static size_t	asm_match_label(t_asm_data *data, t_lab_ref *lab_ref)
{
	size_t		i;
	t_lab_dec	*tmp;

	i = 0;
	while (i < CHAMP_MAX_SIZE)
	{
		tmp = *(data->label_tab + i);
		while (!(tmp == NULL))
		{
			if (!ft_strcmp(tmp->label_name, lab_ref->label_name))
			{
				return (i);
			}
			tmp = tmp->next;
		}
		i++;
	}
	return (i);
}

static int		aux_asm_check_labels(t_asm_data *data, t_lab_ref *label_ref,\
																	char *prog)
{
	unsigned int		relative;
	size_t				i;

	i = asm_match_label(data, label_ref);
	if (i < CHAMP_MAX_SIZE)
	{
		relative = (unsigned int)(i - label_ref->op_code_pos);
		if ((label_ref->size == 2\
					&& asm_putusint_prog(prog, &(label_ref->ref_pos), \
						(unsigned short int)relative))
				|| (label_ref->size == 4\
					&& asm_putuint_prog(prog, &(label_ref->ref_pos), relative)))
		{
			return (1);
		}
	}
	return (asm_inexisting_label_reference(label_ref->label_name));
}

/*
** On avait egalement le choix de liberer la memoire associee aux maillons de la
** liste chainee et fur et a mesure du parcours de cette derniere
*/

static int		asm_check_labels(t_asm_data *data, char *prog)
{
	t_lab_ref	*tmp;

	tmp = data->label_refs;
	while (!(tmp == NULL))
	{
		if (!aux_asm_check_labels(data, tmp, prog))
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

/*
** Rappel :
** (char *)prog est un tableau de char de dimension CHAMP_MAX_SIZE
**
** La variable de retour de 'asm_parse_line' 'ret_val'
** peut valoir '-1' pour 4 raisons :
** - dans 'asm_gn_pertinent_l' :
**     - un appel de 'gnl' a renvoye la valeur '-1'
** - dans 'asm_get_label_declaration' :
**     - la variable '*(data->label_tab + pos)' n'etait pas a NULL
**       alors qu'un nouveau label a ete decouvert a la position 'pos'
**     - 'ft_strdup' a renvoye NULL
** - 'asm_parse_instruction' a renvoye '0'
**
**	ft_putstr("asm_parse_prog\n");
**	h->prog_size = 23; // "zork"
*/

int				asm_parse_prog(t_asm_data *data, t_header *h, char **line,\
																	char *prog)
{
	int			ret_val;
	t_asm_inst	inst;
	size_t		pos;

	pos = 0;
	inst.prog = prog;
	data->current_inst = &inst;
	while ((ret_val = asm_parse_line(data, line, &pos)) == 1)
		;
	if (ret_val == 0)
	{
		h->prog_size = pos;
		return (asm_check_labels(data, prog));
	}
	else
	{
		return (0);
	}
}
