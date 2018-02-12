/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specify_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 01:52:41 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/12 02:06:04 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	specify_base(char c, ULLI nb, t_pf *mai, ssize_t mnoz)
{
	if (c == 'd' || c == 'i' || c == 'u')
	{
		add_nb_mai(nb, "0123456789", mai, mnoz);
	}
	else if (c == 'o')
	{
		add_nb_mai(nb, "01234567", mai, mnoz);
	}
	else if (c == 'x')
	{
		add_nb_mai(nb, "0123456789abcdef", mai, mnoz);
	}
	else if (c == 'X')
	{
		add_nb_mai(nb, "0123456789ABCDEF", mai, mnoz);
	}
	else
	{
		error_code("Erreur dans \"ft_printf\"");
	}
}
