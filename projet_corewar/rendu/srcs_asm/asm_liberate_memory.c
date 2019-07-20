/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_liberate_memory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:28:30 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/08 17:28:31 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

/*
** Un autre endroit pour liberer la memoire associee
** aux references a des labels serait dans la fonction
** 'asm_check_labels' du fichier 'asm_parse_prog.c'
*/

static void	asm_liberate_label_refs(t_asm_data *data)
{
	t_lab_ref	*to_free;

	while (!(data->label_refs == NULL))
	{
		to_free = data->label_refs;
		data->label_refs = (data->label_refs)->next;
		if (!(to_free->label_name == NULL))
		{
			free(to_free->label_name);
		}
		free(to_free);
	}
}

static void	asm_liberate_labels(t_asm_data *data)
{
	size_t		i;
	t_lab_dec	*to_free;

	i = 0;
	while (i < CHAMP_MAX_SIZE)
	{
		while (!((to_free = *(data->label_tab + i)) == NULL))
		{
			*(data->label_tab + i) = (*(data->label_tab + i))->next;
			if (!(to_free->label_name == NULL))
			{
				free(to_free->label_name);
			}
			free(to_free);
		}
		i++;
	}
}

void		asm_liberate_memory(t_asm_data *data)
{
	if (!(data->output_file_name == NULL))
	{
		free(data->output_file_name);
	}
	if (!(data->input_fd == -1))
	{
		close(data->input_fd);
	}
	if (!(data->output_fd == -1))
	{
		close(data->output_fd);
	}
	asm_liberate_labels(data);
	asm_liberate_label_refs(data);
}
