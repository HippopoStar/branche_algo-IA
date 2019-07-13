#include "ft_asm.h"

static void	asm_put_warning(void)
{
	ft_putstr_fd("\033[33mWARNING\033[00m: ", 2);
}

int			asm_two_labels_in_a_row(t_asm_data *data)
{
	asm_put_warning();
	ft_putstr_fd("two label declarations in a row - line ", 2);
	ft_putnbr_fd(data->current_line_nb, 2);
	ft_putchar_fd('\n', 2);
	return (1);
}

int			asm_label_name_already_exists(char *label_name)
{
	asm_put_warning();
	ft_putstr_fd("two identical label declarations - \"", 2);
	ft_putstr_fd(label_name, 2);
	ft_putstr_fd("\"\n", 2);
	return (1);
}
