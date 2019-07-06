#include "ft_asm.h"

/*
** On a necessairement
** h->prog_size < CHAMP_MAX_SIZE
*/

int		asm_put_prog_output(t_data *data, t_header *h, char *prog)
{
	size_t	i;

	data->output_index = FT_HEADER_LENGTH;
	i = 0;
	while (i < h->prog_size)
	{
		if (!asm_putchar_output(data, *(prog + i)))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
