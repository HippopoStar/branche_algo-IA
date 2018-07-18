#include "libftprintf.h"

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
	return (0);
}
