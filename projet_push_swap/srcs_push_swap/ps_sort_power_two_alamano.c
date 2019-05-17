#include "push_swap.h"

void	ps_sort_power_two_alamano(t_ps *data)
{
	size_t	len;

	len = data->length;
	while (len > 7)
	{
		ps_do(data, "rra\0rra\0rra\0rra\0\0");
		ps_alamano_a(data);
		ps_do(data, "rra\0rra\0rra\0rra\0\0");
		ps_alamano_b(data);
		len = len - 8;
	}
	if (len > 3)
	{
		ps_do(data, "rra\0rra\0rra\0rra\0\0");
		ps_alamano_a(data);
		ps_do(data, "rra\0rra\0rra\0rra\0\0");
		ps_aux_alamano_b(data);
	}
	else if (len > 0)
	{
		while (len > 0)
		{
			ps_do(data, "rra\0\0");
			len--;
		}
		ps_aux_alamano_a(data);
	}
}
