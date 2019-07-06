#include "ft_asm.h"

static int	asm_put_magic_output(t_asm_data *data, t_header *h)
{
	if (data->output_index == 0
			&& asm_putuint_output(data, h->magic))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		asm_put_header_output(t_asm_data *data, t_header *h)
{
	if (asm_put_magic_output(data, h))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
