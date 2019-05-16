#include "push_swap.h"

void	ps_alamano_one(t_ps *data, int e, int f, int g)
{
	if (e < f && e < g && f < g)
	{
		ps_do(data, "ra\0ra\0ra\0ra\0\0");
	}
	else if (e < f && e < g && f > g)
	{
		ps_do(data, "ra\0ra\0sa\0ra\0ra\0\0");
	}
	else if (e > f && e < g && f < g)
	{
		ps_do(data, "ra\0sa\0ra\0ra\0ra\0\0");
	}
	else if (e < f && e > g && f > g)
	{
		ps_do(data, "ra\0pb\0sa\0ra\0pa\0ra\0ra\0\0");
	}
	else if (e > f && e > g && f < g)
	{
		ps_do(data, "ra\0sa\0ra\0sa\0ra\0ra\0\0");
	}
	else
	{
		ps_do(data, "ra\0pb\0sa\0ra\0ra\0pa\0ra\0\0");
	}
}

void	ps_alamano_two(t_ps *data, int e, int f, int g)
{
	if (e < f && e < g && f < g)
	{
		ps_do(data, "sa\0ra\0ra\0ra\0ra\0\0");
	}
	else if (e < f && e < g && f > g)
	{
		ps_do(data, "sa\0ra\0ra\0sa\0ra\0ra\0\0");
	}
	else if (e > f && e < g && f < g)
	{
		ps_do(data, "pb\0sa\0ra\0pa\0ra\0ra\0ra\0\0");
	}
	else if (e < f && e > g && f > g)
	{
		ps_do(data, "pb\0pb\0sa\0ra\0pa\0pa\0ra\0ra\0ra\0\0");
	}
	else if (e > f && e > g && f < g)
	{
		ps_do(data, "pb\0sa\0ra\0pa\0ra\0sa\0ra\0ra\0\0");
	}
	else
	{
		ps_do(data, "pb\0pb\0ss\0ra\0pa\0ra\0ra\0pa\0ra\0\0");
	}
}

void	ps_alamano_three(t_ps *data, int e, int f, int g)
{
	if (e < f && e < g && f < g)
	{
		ps_do(data, "pb\0ra\0ra\0pa\0ra\0ra\0\0");
	}
	else if (e < f && e < g && f > g)
	{
		ps_do(data, "pb\0ra\0sa\0ra\0pa\0ra\0ra\0\0");
	}
	else if (e > f && e < g && f < g)
	{
		ps_do(data, "pb\0sa\0ra\0ra\0pa\0ra\0ra\0\0");
	}
	else if (e < f && e > g && f > g)
	{
		ps_do(data, "pb\0pb\0ss\0ra\0pa\0pa\0ra\0ra\0ra\0\0");
	}
	else if (e > f && e > g && f < g)
	{
		ps_do(data, "pb\0pb\0ra\0ra\0pa\0pa\0ra\0ra\0\0");
	}
	else
	{
		ps_do(data, "pb\0pb\0sa\0ra\0ra\0pa\0pa\0ra\0ra\0\0");
	}
}

void	ps_alamano_four(t_ps *data, int e, int f, int g)
{
	if (e < f && e < g && f < g)
	{
		ps_do(data, "pb\0ra\0ra\0ra\0pa\0ra\0\0");
	}
	else if (e < f && e < g && f > g)
	{
		ps_do(data, "pb\0ra\0sa\0ra\0ra\0pa\0ra\0\0");
	}
	else if (e > f && e < g && f < g)
	{
		ps_do(data, "pb\0sa\0ra\0ra\0ra\0pa\0ra\0\0");
	}
	else if (e < f && e > g && f > g)
	{
		ps_do(data, "pb\0pb\0sa\0ra\0pa\0ra\0ra\0pa\0ra\0\0");
	}
	else if (e > f && e > g && f < g)
	{
		ps_do(data, "pb\0sa\0ra\0sa\0ra\0ra\0pa\0ra\0\0");
	}
	else
	{
		ps_do(data, "pb\0pb\0sa\0ra\0ra\0pa\0ra\0pa\0ra\0\0");
	}
}

void	ps_alamano(t_ps *data, size_t len)
{
	int		a;
	int		b;
	int		c;
	int		d;

	while (len > 0)
	{
		a = (*(data->stacks + 0))->nb;
		b = ((*(data->stacks + 0))->next)->nb;
		c = (((*(data->stacks + 0))->next)->next)->nb;
		d = ((((*(data->stacks + 0))->next)->next)->next)->nb;
		if (a < b && a < c && a < d)
		{
			ps_alamano_one(data, b, c, d);
		}
		else if ((a < b && a < c) || (a < b && a < d) || (a < c && a < d))
		{
			ps_alamano_two(data, b, c, d);
		}
		else if (a < b || a < c || a < d)
		{
			ps_alamano_three(data, b, c, d);
		}
		else
		{
			ps_alamano_four(data, b, c, d);
		}
		len = len - 4;
	}
}
