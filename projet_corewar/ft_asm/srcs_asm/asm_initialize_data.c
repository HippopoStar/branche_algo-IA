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

static void	asm_initialize_data_output(t_asm_data *data)
{
	size_t	i;

	i = 0;
	while (i < ASM_CHAMP_LENGTH)
	{
		*(data->output + i) = '\0';
		i++;
	}
	*(data->output + ASM_CHAMP_LENGTH) = EOF;
}

void	asm_initialize_data(t_asm_data *data)
{
	data->input_fd = -1;
	data->output_file_name = NULL;
	data->output_fd = -1;
	asm_initialize_data_output(data);
	data->output_index = 0;
	asm_initialize_data_label_tab(data);
}
