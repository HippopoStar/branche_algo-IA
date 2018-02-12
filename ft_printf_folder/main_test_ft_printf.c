/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_ft_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:52:23 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/12 11:47:08 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int		main(int argc, char **argv)
{
	char			*a;
	long long int	b;
	char			c;
	wchar_t			uni;

	uni = L'α';
//	uni = L'一';
//	uni = L'a';
	setlocale(LC_ALL, "");
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
			b = ft_atoi(*(argv + 3)); // N'interprete pas les ULLI
			if (argc > 4)
			{
				c = *(*(argv + 4) + 0);
			}
		}
	}
	ft_printf(*(argv + 1), a, b, uni);
	ft_putchar('\n');
	printf(*(argv + 1), a, b, uni);
	printf("\n");
	printf("LLONG_MIN vaut : %lld", LLONG_MIN);
	printf("\n");
	printf("ULLONG_MAX vaut : %llu", ULLONG_MAX);
	printf("\n");
	ft_printf("the unicode test : %C \n", uni);
	printf("the unicode test : %C \n", uni);
	return (0);
}
