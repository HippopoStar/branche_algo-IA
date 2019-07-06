#include "ft_asm.h"

int		asm_putchar_prog(char *prog, size_t *i, char c)
{
	if ((*i) < CHAMP_MAX_SIZE)
	{
		*(prog + (*i)) = c;
		(*i)++;
		return (1);
	}
	else
	{
		return (0);
	}
}

int		asm_putusint_prog(char *prog, size_t *i, unsigned short int s)
{
	if (asm_putchar_prog(prog, i, (char)(s >> 8))
			&& asm_putchar_prog(prog, i, (char)s))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		asm_putuint_prog(char *prog, size_t *i, unsigned int u)
{
	if (asm_putchar_prog(prog, i, (char)(u >> 24))
			&& asm_putchar_prog(prog, i, (char)(u >> 16))
			&& asm_putchar_prog(prog, i, (char)(u >> 8))
			&& asm_putchar_prog(prog, i, (char)u))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
