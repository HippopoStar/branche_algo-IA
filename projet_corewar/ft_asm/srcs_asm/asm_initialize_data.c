/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_initialize_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:06:56 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/05 16:20:30 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

static void	asm_initialize_data_label_tab(t_asm_data *data)
{
	size_t	i;

	i = 0;
	while (i < CHAMP_MAX_SIZE)
	{
		*(data->label_tab + i) = NULL;
		i++;
	}
}

/*
** Precedement, la taille du tableau de char
** (t_asm_data *)->output
** etait de ASM_CHAMP_LENGTH + 1,
** la derniere instruction de la fonction
** 'asm_initialize_data_output' etait
**	*(data->output + FT_CHAMP_LENGTH) = EOF;
*/

static void	asm_initialize_data_output(t_asm_data *data)
{
	size_t	i;

	*(data->output + 0) = (char)0xea;
	*(data->output + 1) = (char)0x83;
	*(data->output + 2) = (char)0xf3;
	i = 3;
	while (i < FT_CHAMP_LENGTH)
	{
		*(data->output + i) = '\0';
		i++;
	}
}

/*
** Etant donne que la variable (t_asm_data *)->current_inst
** sera toujours declaree sur la stack,
** il n'est pas veritablement necessaire de l'initialiser
** a NULL
*/

void	asm_initialize_data(t_asm_data *data)
{
	data->input_fd = -1;
	data->output_file_name = NULL;
	data->output_fd = -1;
	asm_initialize_data_output(data);
	data->output_index = 0;
	asm_initialize_data_label_tab(data);
	data->label_refs = NULL;
}
