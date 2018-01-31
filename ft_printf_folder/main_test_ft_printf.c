/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_ft_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:52:23 by lcabanes          #+#    #+#             */
/*   Updated: 2018/01/31 17:58:24 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Passez en argument au programme la phrase a ecrire");
	}
	else
	{
		ft_printf(*(argv + 1));
	}
	return (0);
}
