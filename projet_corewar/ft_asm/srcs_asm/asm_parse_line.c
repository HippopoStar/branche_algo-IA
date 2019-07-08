#include "ft_asm.h"

/*
**	ft_putstr("asm_parse_line\n");
**		ft_putstr(&(*((*line) + i)));
*/

int		asm_parse_line(t_asm_data *data, char **line, size_t *pos)
{
	int		ret_gnl;
	size_t	i;

	ret_gnl = asm_gn_pertinent_l(data, line, &i);
	if (ret_gnl == 1)
	{
		if (!asm_get_label_declaration(data, *line, &i, *pos))
		{
			return (-1);
		}
		return (asm_parse_instruction(data, *line, i, pos) == 1 ? 1 : -1);
	}
	return (ret_gnl);
}
