#include "ft_asm.h"

int		asm_parse_line(t_asm_data *data, char **line, size_t *pos)
{
	int		ret_gnl;
	size_t	i;

	ret_gnl = asm_gn_pertinent_l(data, line, &i);
	if (ret_gnl == 1)
	{
		asm_get_label_declaration(data, *line, &i, *pos);
		return (asm_parse_instruction(data, *line, i, pos));
	}
	return (ret_gnl);
}
