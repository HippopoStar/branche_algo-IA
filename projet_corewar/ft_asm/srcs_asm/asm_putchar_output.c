#include "ft_asm.h"

int		asm_putchar_output(t_asm_data *data, char c)
{
	if (data->output_index < FT_CHAMP_LENGTH)
	{
		*(data->output + data->output_index) = c;
		(data->output_index)++;
		return (1);
	}
	else
	{
		return (0);
	}
}

int		asm_putsuint_output(t_asm_data *data, unsigned short int s)
{
	if (asm_putchar_output(data, (char)(s >> 8))
			&& asm_putchar_output(data, (char)s))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		asm_putuint_output(t_asm_data *data, unsigned int u)
{
	if (asm_putchar_output(data, (char)(u >> 24))
			&& asm_putchar_output(data, (char)(u >> 16))
			&& asm_putchar_output(data, (char)(u >> 8))
			&& asm_putchar_output(data, (char)u))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
