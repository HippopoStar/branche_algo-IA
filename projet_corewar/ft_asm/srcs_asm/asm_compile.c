#include "ft_asm.h"

int		asm_compile(t_asm_data *data)
{
	char		*line;
	t_header	h;
	char		prog[CHAMP_MAX_SIZE];

	line = NULL;
	if (asm_parse_header(data, &h, &line) && asm_parse_prog(data, &line, prog))
	{
		h.prog_size = (unsigned int)data->output_index - (unsigned int)FT_HEADER_LENGTH;
		if (asm_put_header_output(data, &h) && asm_put_prog_output(data, &h, prog))
		{
			return (1);
		}
	}
	if (!(line == NULL))
	{
		free(line);
	}
	return (0);
}
