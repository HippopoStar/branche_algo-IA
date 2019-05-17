/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_aux_alamano.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:36:25 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/17 17:06:20 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_aux_aux_alamano(t_ps *data, int a, int b, int c)
{
	if (a < b && b < c)
	{
		ps_do(data, "ra\0ra\0ra\0\0");
	}
	else if (a < c && c < b)
	{
		ps_do(data, "ra\0sa\0ra\0ra\0\0");
	}
	else if (b < a && a < c)
	{
		ps_do(data, "sa\0ra\0ra\0ra\0\0");
	}
	else if (c < a && a < b)
	{
		ps_do(data, "pb\0sa\0ra\0pa\0ra\0ra\0\0");
	}
	else if (b < c && c < a)
	{
		ps_do(data, "sa\0ra\0sa\0ra\0ra\0\0");
	}
	else
	{
		ps_do(data, "pb\0sa\0ra\0ra\0pa\0ra\0\0");
	}
}

void	ps_aux_alamano(t_ps *data)
{
	int		a;
	int		b;
	int		c;

	if (data->length % 4 > 0)
	{
		a = (*(data->stacks + 0))->nb;
		if (data->length % 4 == 1)
			ps_do(data, "ra\0\0");
		else
		{
			b = ((*(data->stacks + 0))->next)->nb;
			if (data->length % 4 == 2)
			{
				ps_do(data, (a < b ? "ra\0ra\0\0" : "sa\0ra\0ra\0\0"));
			}
			else
			{
				c = (((*(data->stacks + 0))->next)->next)->nb;
				ps_aux_aux_alamano(data, a, b, c);
			}
		}
	}
	ps_alamano(data, data->length - (data->length % 4));
}
