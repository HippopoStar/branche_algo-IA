/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error_messages_03.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:27:24 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/11 02:41:53 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

int		asm_two_labels_in_a_row(t_asm_data *data)
{
	ft_putstr_fd("ERROR: two label declarations in a row - line ", 2);
	ft_putnbr_fd(data->current_line_nb, 2);
	ft_putchar_fd('\n', 2);
	return (0);
}

int		asm_label_name_already_exists(char *label_name)
{
	ft_putstr_fd("ERROR: two identical label declarations - \"", 2);
	ft_putstr_fd(label_name, 2);
	ft_putstr_fd("\"\n", 2);
	return (0);
}

int		asm_inexisting_label_reference(char *label_name)
{
	ft_putstr_fd("ERROR: reference to an unexisting label \"", 2);
	ft_putstr_fd(label_name, 2);
	ft_putstr_fd("\"\n", 2);
	return (0);
}

int		asm_error_message_reading_stopped(t_asm_data *data)
{
	ft_putstr_fd("- \033[33merror\033[00m - file \"", 2);
	ft_putstr_fd(data->input_file_name, 2);
	ft_putstr_fd("\" - reading stopped at line ", 2);
	ft_putnbr_fd(data->current_line_nb, 2);
	ft_putchar_fd('\n', 2);
	return (0);
}
