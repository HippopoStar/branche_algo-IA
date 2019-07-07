#include "ft_asm.h"

int		asm_putchar_prog(char *prog, size_t *pos, char c)
{
	if ((*pos) < CHAMP_MAX_SIZE)
	{
		*(prog + (*pos)) = c;
		(*pos)++;
		return (1);
	}
	else
	{
		return (0);
	}
}

int		asm_putusint_prog(char *prog, size_t *pos, unsigned short int s)
{
	if (asm_putchar_prog(prog, pos, (char)(s >> 8))
			&& asm_putchar_prog(prog, pos, (char)s))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		asm_putuint_prog(char *prog, size_t *pos, unsigned int u)
{
	if (asm_putchar_prog(prog, pos, (char)(u >> 24))
			&& asm_putchar_prog(prog, pos, (char)(u >> 16))
			&& asm_putchar_prog(prog, pos, (char)(u >> 8))
			&& asm_putchar_prog(prog, pos, (char)u))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
