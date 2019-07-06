/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_open_input_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:08:40 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/05 16:50:27 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

/*
** Allocation dynamique de memoire dans 'asm_open_input_file'
** (char *)data->output_file_name
*/

int		asm_open_input_file(t_asm_data *data)
{
	size_t	name_length;

	name_length = ft_strlen(data->input_file_name);
	if (name_length > 2\
			&& !(*(data->input_file_name + name_length - 3) == '/')\
			&& *(data->input_file_name + name_length - 2) == '.'\
			&& *(data->input_file_name + name_length - 1) == 's')
	{
		if (!(data->output_file_name = (char *)malloc((name_length + 3)\
						* sizeof(char))))
			return (asm_memory_allocation_fail());
		ft_strcpy(data->output_file_name, data->input_file_name);
		*(data->output_file_name + name_length - 1) = 'c';
		*(data->output_file_name + name_length) = 'o';
		*(data->output_file_name + name_length + 1) = 'r';
		*(data->output_file_name + name_length + 2) = '\0';
		if ((data->input_fd = open(data->input_file_name, O_RDONLY)) == -1)
			return (asm_input_file_open_fail(data));
		return (1);
	}
	return (asm_incorrect_input_file_name(data));
}
