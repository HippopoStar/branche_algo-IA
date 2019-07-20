/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_compile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:54:59 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/08 17:55:51 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

static void	asm_liberate_gnl_node(int fd, char **line)
{
	int		ret_gnl;

	while ((ret_gnl = get_next_line_backslash_zero(fd, line)) == 1)
	{
		free(*line);
		(*line) = NULL;
	}
	if (!((*line) == NULL))
	{
		free(*line);
	}
}

/*
** Retrait de la variable '(char *)line' et remplacement
** par '(char *)data->current_line'
** Objectif : faciliter l'implementation de 'asm_get_quote' autorisant les '\n'
**            et permettre une meilleure gestion d'erreur
**
** //
**	ft_putstr("Erreur mais creation du fichier avec ce qu'on a\n");
**	if (asm_put_header_output(data, &h) && asm_put_prog_output(data, &h, prog))
**	{
**		data->total_size = FT_HEADER_LENGTH + h.prog_size;
**		return (1);
**	}
** //
*/

int			asm_compile(t_asm_data *data)
{
	t_header	h;
	char		prog[CHAMP_MAX_SIZE];

	data->current_line = NULL;
	if (asm_parse_header(data, &h, &(data->current_line))\
			&& asm_parse_prog(data, &h, &(data->current_line), prog))
	{
		if (asm_put_header_output(data, &h)\
				&& asm_put_prog_output(data, &h, prog))
		{
			data->total_size = FT_HEADER_LENGTH + h.prog_size;
			return (1);
		}
	}
	asm_error_message_reading_stopped(data);
	if (!(data->current_line == NULL))
	{
		free(data->current_line);
		data->current_line = NULL;
		asm_liberate_gnl_node(data->input_fd, &(data->current_line));
	}
	return (0);
}
