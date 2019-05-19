/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_aux_alamano_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:04:13 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/19 17:04:14 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_aux_aux_alamano_b(t_ps *data, int a, int b, int c)
{
	if (a < b && b < c)
	{
		ps_do(data, "rb\0sb\0pa\0pa\0rrb\0pa\0\0");
	}
	else if (a < c && c < b)
	{
		ps_do(data, "sb\0pa\0sb\0pa\0pa\0\0");
	}
	else if (b < a && a < c)
	{
		ps_do(data, "pa\0sb\0pa\0sa\0pa\0\0");
	}
	else if (c < a && a < b)
	{
		ps_do(data, "sb\0pa\0pa\0pa\0\0");
	}
	else if (b < c && c < a)
	{
		ps_do(data, "pa\0sb\0pa\0pa\0\0");
	}
	else
	{
		ps_do(data, "pa\0pa\0pa\0\0");
	}
}

void	ps_aux_alamano_b(t_ps *data)
{
	int		a;
	int		b;
	int		c;

	if (data->length % 4 > 0)
	{
		a = (*(data->stacks + 1))->nb;
		if (data->length % 4 == 1)
			ps_do(data, "pa\0\0");
		else
		{
			b = ((*(data->stacks + 1))->next)->nb;
			if (data->length % 4 == 2)
			{
				ps_do(data, (a < b ? "sb\0pa\0pa\0\0" : "pa\0pa\0\0"));
			}
			else
			{
				c = (((*(data->stacks + 1))->next)->next)->nb;
				ps_aux_aux_alamano_b(data, a, b, c);
			}
		}
	}
}
