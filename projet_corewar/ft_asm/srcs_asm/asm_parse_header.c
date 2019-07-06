#include "ft_asm.h"

int		asm_parse_header(t_asm_data *data, t_header *h)
{
	(void)data;
	h->magic = (unsigned int)COREWAR_EXEC_MAGIC;
	return (1);
}
