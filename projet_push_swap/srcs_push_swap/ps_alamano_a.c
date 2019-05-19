/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alamano_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:03:57 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/19 17:03:58 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_alamano_a_one(t_ps *data, int e, int f, int g)
{
	if (e < f && e < g && f < g)
	{
		ps_do(data, "rra\0rra\0rra\0rra\0\0");
	}
	else if (e < f && e < g && f > g)
	{
		ps_do(data, "rra\0rra\0sa\0rra\0rra\0\0");
	}
	else if (e > f && e < g && f < g)
	{
		ps_do(data, "rra\0rra\0rra\0sa\0rra\0\0");
	}
	else if (e < f && e > g && f > g)
	{
		ps_do(data, "rra\0rra\0sa\0rra\0sa\0rra\0\0");
	}
	else if (e > f && e > g && f < g)
	{
		ps_do(data, "rra\0rra\0pb\0rra\0sa\0pa\0rra\0\0");
	}
	else
	{
		ps_do(data, "rra\0pb\0rra\0rra\0sa\0pa\0rra\0\0");
	}
}

void	ps_alamano_a_two(t_ps *data, int e, int f, int g)
{
	if (e < f && e < g && f < g)
	{
		ps_do(data, "rra\0rra\0rra\0rra\0sa\0\0");
	}
	else if (e < f && e < g && f > g)
	{
		ps_do(data, "rra\0rra\0sa\0rra\0rra\0sa\0\0");
	}
	else if (e > f && e < g && f < g)
	{
		ps_do(data, "rra\0rra\0rra\0sa\0rra\0sa\0\0");
	}
	else if (e < f && e > g && f > g)
	{
		ps_do(data, "rra\0pb\0rra\0rra\0rra\0pa\0\0");
	}
	else if (e > f && e > g && f < g)
	{
		ps_do(data, "rra\0rra\0pb\0rra\0sa\0rra\0pa\0\0");
	}
	else
	{
		ps_do(data, "rra\0pb\0rra\0rra\0sa\0rra\0pa\0\0");
	}
}

void	ps_alamano_a_three(t_ps *data, int e, int f, int g)
{
	if (e < f && e < g && f < g)
	{
		ps_do(data, "rra\0rra\0pb\0rra\0rra\0sa\0pa\0sa\0\0");
	}
	else if (e < f && e < g && f > g)
	{
		ps_do(data, "rra\0pb\0rra\0rra\0rra\0sa\0pa\0sa\0\0");
	}
	else if (e > f && e < g && f < g)
	{
		ps_do(data, "rra\0rra\0pb\0rra\0rra\0sa\0pa\0\0");
	}
	else if (e < f && e > g && f > g)
	{
		ps_do(data, "rra\0pb\0rra\0rra\0rra\0sa\0pa\0\0");
	}
	else if (e > f && e > g && f < g)
	{
		ps_do(data, "rra\0rra\0pb\0pb\0rra\0rra\0pa\0pa\0\0");
	}
	else
	{
		ps_do(data, "rra\0pb\0rra\0pb\0rra\0rra\0pa\0pa\0\0");
	}
}

void	ps_alamano_a_four(t_ps *data, int e, int f, int g)
{
	if (e < f && e < g && f < g)
	{
		ps_do(data, "rra\0rra\0rra\0pb\0pb\0rra\0sa\0pa\0pa\0\0");
	}
	else if (e < f && e < g && f > g)
	{
		ps_do(data, "rra\0pb\0rra\0rra\0pb\0rra\0ss\0pa\0pa\0\0");
	}
	else if (e > f && e < g && f < g)
	{
		ps_do(data, "rra\0rra\0rra\0pb\0pb\0rra\0ss\0pa\0pa\0\0");
	}
	else if (e < f && e > g && f > g)
	{
		ps_do(data, "rra\0pb\0rra\0rra\0pb\0rra\0sa\0pa\0pa\0\0");
	}
	else if (e > f && e > g && f < g)
	{
		ps_do(data, "rra\0rra\0pb\0pb\0rra\0rra\0sa\0pa\0pa\0\0");
	}
	else
	{
		ps_do(data, "rra\0rra\0pb\0pb\0rra\0rra\0ss\0pa\0pa\0\0");
	}
}

void	ps_alamano_a(t_ps *data)
{
	int		a;
	int		b;
	int		c;
	int		d;

	a = ps_get_a_four_lasts(data, &b, &c, &d);
	if (a < b && a < c && a < d)
	{
		ps_alamano_a_one(data, b, c, d);
	}
	else if ((a < b && a < c) || (a < b && a < d) || (a < c && a < d))
	{
		ps_alamano_a_two(data, b, c, d);
	}
	else if (a < b || a < c || a < d)
	{
		ps_alamano_a_three(data, b, c, d);
	}
	else
	{
		ps_alamano_a_four(data, b, c, d);
	}
}
