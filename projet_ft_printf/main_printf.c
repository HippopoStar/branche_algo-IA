#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	int	ret_val;

	ret_val = ft_printf("abc\n");
	ft_putnbr(ret_val);
	ft_putchar('\n');
	ret_val = ft_printf("abc%%def\n");
	ft_putnbr(ret_val);
	ft_putchar('\n');
	ret_val = ft_printf("abc{cyan}def{eoc}ghi\n");
	ft_putnbr(ret_val);
	ft_putchar('\n');
	ret_val = ft_printf("ab%c{cyan}%s{eoc}ghi\n", 'c', "def");
	ft_putnbr(ret_val);
	ft_putchar('\n');
	ret_val = ft_printf("a%-3cc{cyan}%20s{eoc}ghi\n", 'b', "def");
	ft_putnbr(ret_val);
	ft_putchar('\n');
	ret_val = ft_printf("a%-3cc{cyan}%20s{eoc}ghi\n", 'b', "def");
	ft_putnbr(ret_val);
	ft_putchar('\n');
	ret_val = ft_printf("a%-3cc%i{cyan}%20s{eoc}ghi\n", 'b', 380, "def");
	ft_putnbr(ret_val);
	ft_putchar('\n');
	ret_val = ft_printf("a%-3cc{cyan}%20s{eoc}%#Xghi\n", 'b', "def", 12);
	ft_putnbr(ret_val);
	ft_putchar('\n');
	return (0);
}
