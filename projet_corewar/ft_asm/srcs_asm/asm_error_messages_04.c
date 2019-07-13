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

int		asm_inexisting_label_reference(char *label_name)
{
	asm_put_error();
	ft_putstr_fd("reference to an unexisting label \"", 2);
	ft_putstr_fd(label_name, 2);
	ft_putstr_fd("\"\n", 2);
	return (0);
}
