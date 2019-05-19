/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alamano_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:03:48 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/19 17:03:51 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_alamano_b_one(t_ps *data, int e, int f, int g)
{
	if (e < f && e < g && f < g)
	{
		ps_do(data, "rb\0rb\0sb\0pa\0pa\0rrb\0pa\0rrb\0pa\0\0");
	}
	else if (e < f && e < g && f > g)
	{
		ps_do(data, "rb\0sb\0pa\0sb\0pa\0pa\0rrb\0pa\0\0");
	}
	else if (e > f && e < g && f < g)
	{
		ps_do(data, "rb\0rb\0sb\0pa\0rrb\0pa\0pa\0rrb\0pa\0\0");
	}
	else if (e < f && e > g && f > g)
	{
		ps_do(data, "rb\0sb\0pa\0pa\0pa\0rrb\0pa\0\0");
	}
	else if (e > f && e > g && f < g)
	{
		ps_do(data, "rb\0pa\0sb\0pa\0pa\0rrb\0pa\0\0");
	}
	else
	{
		ps_do(data, "rb\0pa\0pa\0pa\0rrb\0pa\0\0");
	}
}

void	ps_alamano_b_two(t_ps *data, int e, int f, int g)
{
	if (e < f && e < g && f < g)
	{
		ps_do(data, "rb\0rb\0sb\0pa\0pa\0rrb\0rrb\0pa\0pa\0\0");
	}
	else if (e < f && e < g && f > g)
	{
		ps_do(data, "rb\0rb\0pa\0pa\0rrb\0rrb\0pa\0pa\0\0");
	}
	else if (e > f && e < g && f < g)
	{
		ps_do(data, "rb\0rb\0sb\0pa\0rrb\0pa\0rrb\0pa\0pa\0\0");
	}
	else if (e < f && e > g && f > g)
	{
		ps_do(data, "rb\0rb\0pa\0rrb\0pa\0rrb\0pa\0pa\0\0");
	}
	else if (e > f && e > g && f < g)
	{
		ps_do(data, "rb\0pa\0sb\0pa\0rrb\0pa\0pa\0\0");
	}
	else
	{
		ps_do(data, "sb\0pa\0sb\0pa\0pa\0pa\0\0");
	}
}

void	ps_alamano_b_three(t_ps *data, int e, int f, int g)
{
	if (e < f && e < g && f < g)
	{
		ps_do(data, "pa\0rb\0sb\0pa\0rrb\0ss\0pa\0pa\0\0");
	}
	else if (e < f && e < g && f > g)
	{
		ps_do(data, "pa\0sb\0pa\0ss\0pa\0pa\0\0");
	}
	else if (e > f && e < g && f < g)
	{
		ps_do(data, "pa\0rb\0sb\0pa\0rrb\0sa\0pa\0pa\0\0");
	}
	else if (e < f && e > g && f > g)
	{
		ps_do(data, "pa\0sb\0pa\0sa\0pa\0pa\0\0");
	}
	else if (e > f && e > g && f < g)
	{
		ps_do(data, "pa\0pa\0ss\0pa\0pa\0\0");
	}
	else
	{
		ps_do(data, "pa\0pa\0sa\0pa\0pa\0\0");
	}
}

void	ps_alamano_b_four(t_ps *data, int e, int f, int g)
{
	if (e < f && e < g && f < g)
	{
		ps_do(data, "pa\0rb\0sb\0pa\0pa\0rrb\0pa\0\0");
	}
	else if (e < f && e < g && f > g)
	{
		ps_do(data, "pa\0sb\0pa\0sb\0pa\0pa\0\0");
	}
	else if (e > f && e < g && f < g)
	{
		ps_do(data, "pa\0rb\0sb\0pa\0rrb\0pa\0pa\0\0");
	}
	else if (e < f && e > g && f > g)
	{
		ps_do(data, "pa\0sb\0pa\0pa\0pa\0\0");
	}
	else if (e > f && e > g && f < g)
	{
		ps_do(data, "pa\0pa\0sb\0pa\0pa\0\0");
	}
	else
	{
		ps_do(data, "pa\0pa\0pa\0pa\0\0");
	}
}

void	ps_alamano_b(t_ps *data)
{
	int		a;
	int		b;
	int		c;
	int		d;

	a = (*(data->stacks + 1))->nb;
	b = ((*(data->stacks + 1))->next)->nb;
	c = (((*(data->stacks + 1))->next)->next)->nb;
	d = ((((*(data->stacks + 1))->next)->next)->next)->nb;
	if (a < b && a < c && a < d)
	{
		ps_alamano_b_one(data, b, c, d);
	}
	else if ((a < b && a < c) || (a < b && a < d) || (a < c && a < d))
	{
		ps_alamano_b_two(data, b, c, d);
	}
	else if (a < b || a < c || a < d)
	{
		ps_alamano_b_three(data, b, c, d);
	}
	else
	{
		ps_alamano_b_four(data, b, c, d);
	}
}
