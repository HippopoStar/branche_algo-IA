/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 23:59:07 by lcabanes          #+#    #+#             */
/*   Updated: 2018/04/17 01:30:47 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_error_code(char *error_message)
{
	ft_putstr("Erreur dans \"ft_printf\" :\n");
	ft_putstr(error_message);
	ft_putchar('\n');
	exit(-1);
}
