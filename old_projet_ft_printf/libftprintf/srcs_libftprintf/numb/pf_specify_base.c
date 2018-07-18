/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specify_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 01:52:41 by lcabanes          #+#    #+#             */
/*   Updated: 2018/04/17 01:25:56 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_specify_base(char c, ULLI nb, t_pf *mai, ssize_t mnoz)
{
	if (c == 'd' || c == 'i' || c == 'u')
	{
		pf_add_nb_mai(nb, "0123456789", mai, mnoz);
	}
	else if (c == 'o')
	{
		pf_add_nb_mai(nb, "01234567", mai, mnoz);
	}
	else if (c == 'x' || c == 'p')
	{
		pf_add_nb_mai(nb, "0123456789abcdef", mai, mnoz);
	}
	else if (c == 'X')
	{
		pf_add_nb_mai(nb, "0123456789ABCDEF", mai, mnoz);
	}
	else
	{
		pf_error_code("Erreur dans \"specify_base.c\\specify_base\"");
	}
}
