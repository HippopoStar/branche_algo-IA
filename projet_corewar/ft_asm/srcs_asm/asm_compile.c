#include "ft_asm.h"

/*
** //
**	ft_putstr("Erreur mais creation du fichier avec ce qu'on a\n");
**	if (asm_put_header_output(data, &h) && asm_put_prog_output(data, &h, prog))
**	{
**		data->total_size = FT_HEADER_LENGTH + h.prog_size;
**		return (1);
**	}
** //
*/

int		asm_compile(t_asm_data *data)
{
	char		*line;
	t_header	h;
	char		prog[CHAMP_MAX_SIZE];

	line = NULL;
	if (asm_parse_header(data, &h, &line) && asm_parse_prog(data, &h, &line, prog))
	{
		if (asm_put_header_output(data, &h) && asm_put_prog_output(data, &h, prog))
		{
			data->total_size = FT_HEADER_LENGTH + h.prog_size;
			return (1);
		}
	}
	if (!(line == NULL))
	{
		free(line);
	}
	return (asm_error_message_reading_stopped(data));
}
