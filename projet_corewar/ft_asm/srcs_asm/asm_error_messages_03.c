#include "ft_asm.h"

int		asm_inexisting_label_reference(char *label_name)
{
	ft_putstr_fd("ERROR: reference to inexisting label \"", 2);
	ft_putstr_fd(label_name, 2);
	ft_putstr_fd("\"\n", 2);
	return (0);
}
