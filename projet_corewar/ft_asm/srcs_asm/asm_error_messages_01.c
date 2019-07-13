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

void	asm_put_error(void)
{
	ft_putstr_fd("\033[31mERROR\033[00m: ", 2);
}

int		asm_error_message_reading_stopped(t_asm_data *data)
{
	ft_putstr_fd("- \033[31merror\033[00m - file \"", 2);
	ft_putstr_fd(data->input_file_name, 2);
	ft_putstr_fd("\" - reading stopped at line ", 2);
	ft_putnbr_fd(data->current_line_nb, 2);
	ft_putchar_fd('\n', 2);
	return (0);
}
