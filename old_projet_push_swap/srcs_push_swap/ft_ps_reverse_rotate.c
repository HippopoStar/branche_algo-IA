/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:41:14 by lcabanes          #+#    #+#             */
/*   Updated: 2018/10/11 16:23:20 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_reverse_rotate(t_nb *stacks[2], char c)
{
	t_nb	*stack;

	stack = *(stacks + (c - 'a'));
	if (stack != NULL && stack->next != NULL)
	{
		while ((stack->next)->next != NULL)
		{
			stack = stack->next;
		}
		(stack->next)->next = *(stacks + (c - 'a'));
		*(stacks + (c - 'a')) = stack->next;
		stack->next = NULL;
	}
}
