#include "ft_asm.h"

int		asm_two_labels_in_a_row(t_asm_data *data)
{
	ft_putstr_fd("ERROR: two label declarations in a row - line ", 2);
	ft_putnbr_fd(data->current_line_nb, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int		asm_inexisting_label_reference(char *label_name)
{
	ft_putstr_fd("ERROR: reference to inexisting label \"", 2);
	ft_putstr_fd(label_name, 2);
	ft_putstr_fd("\"\n", 2);
	return (0);
}
