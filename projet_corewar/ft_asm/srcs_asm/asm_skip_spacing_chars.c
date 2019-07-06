#include "ft_asm.h"

void	asm_skip_spacing_chars(char *line, size_t *i)
{
	while (*(line + (*i)) == '\t' || *(line + (*i)) == ' ')
	{
		ft_putstr("skip\n");
		(*i)++;
	}
}
