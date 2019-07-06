#include "ft_asm.h"

static int	asm_parse_name(t_asm_data *data, t_header *h, char **line)
{
	size_t	i;

	(void)h;
	asm_gn_pertinent_l(data, line, &i);
	return (1);
}

static int	asm_parse_comment(t_asm_data *data, t_header *h, char **line)
{
	(void)data;
	(void)h;
	(void)line;
	return (1);
}

int		asm_parse_header(t_asm_data *data, t_header *h, char **line)
{
	h->magic = (unsigned int)COREWAR_EXEC_MAGIC;
	if (asm_parse_name(data, h, line)
			&& asm_parse_comment(data, h, line))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
