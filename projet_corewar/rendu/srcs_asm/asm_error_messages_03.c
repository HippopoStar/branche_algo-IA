/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error_messages_03.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:37:05 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/05 16:47:24 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

int		asm_failed_to_get_prog_name(t_asm_data *data)
{
	asm_put_error();
	ft_putstr_fd("Unable get a program name - line ", 2);
	ft_putnbr_fd(data->current_line_nb, 2);
	ft_putchar_fd('\n', 2);
	return (0);
}

int		asm_failed_to_get_comment(t_asm_data *data)
{
	asm_put_error();
	ft_putstr_fd("Unable get a comment - line ", 2);
	ft_putnbr_fd(data->current_line_nb, 2);
	ft_putchar_fd('\n', 2);
	return (0);
}

int		asm_syntax_error(t_asm_data *data)
{
	asm_put_error();
	ft_putstr_fd("Syntax - line ", 2);
	ft_putnbr_fd(data->current_line_nb, 2);
	ft_putchar_fd('\n', 2);
	return (0);
}
