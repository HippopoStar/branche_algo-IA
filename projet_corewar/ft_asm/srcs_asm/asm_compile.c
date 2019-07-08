#include "ft_asm.h"

static void	asm_liberate_gnl_node(int fd, char **line)
{
	int		ret_gnl;

	while ((ret_gnl = get_next_line_backslash_zero(fd, line)) == 1)
	{
		free(*line);
		(*line) = NULL;
	}
	if (!((*line) == NULL))
	{
		free(*line);
	}
}

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
		line = NULL;
		asm_liberate_gnl_node(data->input_fd, &line);
	}
	return (asm_error_message_reading_stopped(data));
}
