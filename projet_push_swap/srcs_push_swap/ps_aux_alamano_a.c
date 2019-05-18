#include "push_swap.h"

void	ps_aux_aux_alamano_a(t_ps *data, int a, int b, int c)
{
	if (a < b && b < c)
	{
		ps_do(data, "rra\0rra\0rra\0\0");
	}
	else if (a < c && c < b)
	{
		ps_do(data, "rra\0rra\0sa\0rra\0\0");
	}
	else if (b < a && a < c)
	{
		ps_do(data, "rra\0rra\0rra\0sa\0\0");
	}
	else if (c < a && a < b)
	{
		ps_do(data, "rra\0pb\0rra\0rra\0pa\0\0");
	}
	else if (b < c && c < a)
	{
		ps_do(data, "rra\0rra\0pb\0pb\0rra\0pa\0pa\0\0");
	}
	else
	{
		ps_do(data, "rra\0pb\0rra\0pb\0rra\0pa\0pa\0\0");
	}
}

void	ps_aux_alamano_a(t_ps *data)
{
	int		b;
	int		c;
	int		d;

	ps_get_a_four_lasts(data, &b, &c, &d);
	if (data->length % 4 > 0)
	{
		if (data->length % 4 == 1)
			ps_do(data, "rra\0\0");
		else
		{
			if (data->length % 4 == 2)
			{
				ps_do(data, (c < d ? "rra\0rra\0\0" : "rra\0rra\0sa\0\0"));
			}
			else
			{
				ps_aux_aux_alamano_a(data, b, c, d);
			}
		}
	}
}
