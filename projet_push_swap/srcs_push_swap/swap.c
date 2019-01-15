/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:32:49 by lcabanes          #+#    #+#             */
/*   Updated: 2019/01/15 21:39:20 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_ps *data, char c)
{
	(c == 'a') ? ps_aux_swap(data->a, data->a_start, data->a_end, data->length)
		: ps_aux_swap(data->b, data->b_start, data->b_end, data->length);
}

void	ps_aux_swap(int *stack, size_t start, size_t end, size_t length)
{
	int	tmp;

	if (start < length && end < length && end != start)
	{
		tmp = *(stack + start);
		if (start < length - 1)
		{
			*(stack + start) = *(stack + start + 1);
			*(stack + start + 1) = tmp;
		}
		else if (start == length - 1 && end < start)
		{
			*(stack + start) = *(stack + 0);
			*(stack + 0) = tmp;
		}
	}
}
