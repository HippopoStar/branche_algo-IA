#include "ft_asm.h"

int		asm_compile(t_asm_data *data)
{
	char		*line;
	t_header	h;

	line = NULL;
	if (asm_parse_header(data, &h, &line) && asm_put_header_output(data, &h))
	{
		return (1);
	}
	else
	{
		if (!(line == NULL))
		{
			free(line);
		}
		return (0);
	}
}
