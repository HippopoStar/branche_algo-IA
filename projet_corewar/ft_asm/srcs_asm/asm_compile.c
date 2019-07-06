#include "ft_asm.h"

int		asm_compile(t_asm_data *data)
{
	t_header	h;

	if (asm_parse_header(data, &h) && asm_put_header_output(data, &h))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
