/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_create_output_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:26:53 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/10 19:57:16 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

void	asm_create_output_file(t_asm_data *data)
{
	if (!((data->output_fd = open(data->output_file_name,\
						O_CREAT | O_WRONLY | O_TRUNC,\
						S_IRUSR | S_IWUSR)) == -1))
	{
		ft_putstr("\033[32mCreating\033[00m \"");
		ft_putstr(data->output_file_name);
		ft_putstr("\"\n");
		write(data->output_fd, data->output, data->total_size);
	}
	else
	{
		asm_output_file_creation_fail(data);
	}
}
