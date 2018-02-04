/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_ft_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:52:23 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/04 02:33:21 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
//	t_pf	TEST_PF;
	char	*a;
	int		b;
	char	c;

	a = "42Born2Code";
	b = 42;
	c = 'y';
	if (argc != 2)
	{
		ft_putstr("Passez en argument au programme la phrase a ecrire");
	}
	else
	{
		ft_printf(*(argv + 1), a, b, c);
		ft_putchar('\n');
		printf(*(argv + 1), a, b, c);
		ft_putchar('\n');
//		ft_putnbr_base(-2147483648, "0123456789", &TEST_PF, 15);
//		ft_putchar('\n');
		printf("% 20.15ld", -2147483648);
		ft_putchar('\n');
	}
	return (0);
}
