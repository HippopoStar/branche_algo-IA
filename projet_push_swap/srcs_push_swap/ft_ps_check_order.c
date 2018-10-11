/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_check_order.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:05:19 by lcabanes          #+#    #+#             */
/*   Updated: 2018/10/11 17:31:06 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_ps_aux_check_order(t_nb *stack, t_nb *sorted_ref)
{
	if (stack == NULL)
	{
		return (1);
	}
	else
	{
		while (sorted_ref->n != stack->n)
		{
			sorted_ref = sorted_ref->next;
		}
		while (sorted_ref->n == stack->n
				&& sorted_ref->next != NULL && stack->next != NULL)
		{
			sorted_ref = sorted_ref->next;
			stack = stack->next;
		}
		return ((stack == NULL && sorted_ref == NULL) ? 1 : 0);
	}
}

int		ft_ps_check_order(t_nb *stacks[2], t_nb *sorted_refs[2], char c)
{
	if (c == 'r')
	{
		if (ft_ps_aux_check_order(*(stacks + 0), *(sorted_refs + 0)) == 1)
		{
			if (ft_ps_aux_check_order(*(stacks + 1), *(sorted_refs + 1)) == 1)
			{
				return (2);
			}
			return (1);
		}
	}
	else if (c == 'l')
	{
		if (ft_ps_aux_check_order(*(stacks + 1), *(sorted_refs + 1)) == 1)
		{
			if (ft_ps_aux_check_order(*(stacks + 0), *(sorted_refs + 0)) == 1)
			{
				return (2);
			}
			return (1);
		}
	}
	return (0);
}
