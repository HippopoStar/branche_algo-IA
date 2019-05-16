#include "push_swap.h"

void	ps_do(t_ps *data, const char *inst)
{
	size_t	i;

	i = 0;
	while (*(inst + i) != '\0')
	{
		ps_print_ando(data, inst + i);
		while (*(inst + i) != '\0')
		{
			i++;
		}
		i++;
	}
}
