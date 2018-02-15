/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_ft_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:52:23 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/15 03:21:43 by lcabanes         ###   ########.fr       */
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
	wint_t			uni_char;
	wchar_t			*uni_string;

	a = "42Born2Code";
	b = 42;
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
	ft_printf(*(argv + 1), a, b, c);
	ft_putchar('\n');
	printf(*(argv + 1), a, b, c);
	printf("\n");
	printf("LLONG_MIN vaut : %lld", LLONG_MIN);
	printf("\n");
	printf("ULLONG_MAX vaut : %llu", ULLONG_MAX);
	printf("\n");
	setlocale(LC_ALL, "");
//	uni_char = L'α';
	uni_char = L'一';
//	uni_char = L'a';
	ft_printf("the unicode test : %C \n", uni_char);
	printf("the unicode test : %C \n", uni_char);
	uni_string = L"一α一";
	ft_printf("the unicode string test : %S MB is %d  \n", uni_string, MB_CUR_MAX);
	ft_printf("the res is %d \n", printf("the unicode string test : %S \n", uni_string));
	return (0);
}
