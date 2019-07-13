/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error_messages_01.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:37:05 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/08 18:11:12 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

int		asm_memory_allocation_fail(void)
{
	asm_put_error();
	ft_putstr_fd("Memory allocation fail\n", 2);
	return (0);
}

int		asm_input_file_open_fail(t_asm_data *data)
{
	asm_put_error();
	ft_putstr_fd("Unable to open \"", 2);
	ft_putstr_fd(data->input_file_name, 2);
	ft_putstr_fd("\"\n", 2);
	return (0);
}

int		asm_incorrect_input_file_name(t_asm_data *data)
{
	asm_put_error();
	ft_putstr_fd("Filename \"", 2);
	ft_putstr_fd(data->input_file_name, 2);
	ft_putstr_fd("\" does not match a champion's file name format\n", 2);
	return (0);
}

void	asm_output_file_creation_fail(t_asm_data *data)
{
	asm_put_error();
	ft_putstr_fd("Unable to create \"", 2);
	ft_putstr_fd(data->output_file_name, 2);
	ft_putstr_fd("\"\n", 2);
}
