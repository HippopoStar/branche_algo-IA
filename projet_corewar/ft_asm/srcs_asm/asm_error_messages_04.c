/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error_messages_04.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:08:12 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/08 19:14:38 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

int		asm_name_does_not_fit(void)
{
	ft_putstr_fd("Error: 'name' section does not fit - PROG_NAME_LENGTH ", 2);
	ft_putnbr_fd((int)PROG_NAME_LENGTH, 2);
	ft_putchar_fd('\n', 2);
	return (0);
}

int		asm_comment_does_not_fit(void)
{
	ft_putstr_fd("Error: 'comment' section does not fit - COMMENT_LENGTH ", 2);
	ft_putnbr_fd((int)COMMENT_LENGTH, 2);
	ft_putchar_fd('\n', 2);
	return (0);
}

int		asm_program_does_not_fit(void)
{
	ft_putstr_fd("Error: 'program' section does not fit - CHAMP_MAX_SIZE ", 2);
	ft_putnbr_fd((int)CHAMP_MAX_SIZE, 2);
	ft_putchar_fd('\n', 2);
	return (0);
}
