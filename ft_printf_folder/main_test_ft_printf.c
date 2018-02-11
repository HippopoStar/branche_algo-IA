/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_ft_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:52:23 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/11 15:48:59 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char			*a;
	long long int	b;
	char			c;

	a = "42Born2Code";
	b = LLONG_MIN;
	c = 'y';
	if (argc < 2)
	{
		ft_putstr("Passez en argument au programme la phrase a ecrire");
		return (0);
	}
	if (argc > 2)
	{
		a = *(argv + 2);
		if (argc > 3)
		{
			b = ft_atoi(*(argv + 3));
			if (argc > 4)
			{
				c = *(*(argv + 4) + 0);
			}
		}
	}
	ft_printf(*(argv + 1), a, b, c);
	ft_putchar('\n');
	printf(*(argv + 1), a, b, c);
	printf("\n");
	printf("LLONG_MIN vaut : %lld", LLONG_MIN);
	printf("\n");
	return (0);
}
