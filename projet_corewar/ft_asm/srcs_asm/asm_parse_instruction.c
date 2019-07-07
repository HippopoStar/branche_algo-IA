#include "ft_asm.h"

/*
**	ft_putstr("ams_parse_instruction\n");
*/

int		asm_parse_instruction(t_asm_data *data, char *line, size_t i, size_t *pos)
{
	ft_putstr("ams_parse_instruction\n");
	(void)line;
	(void)i;
	if (!(*(line + i) == '\0' || *(line + i) == '#'))
	{
		if (asm_get_inst_op_code(data->current_inst, line, &i))
		{
			(data->current_inst)->op_code_pos = *pos;
		}
	}
	return (1);
}
