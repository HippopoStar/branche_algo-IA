/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:29:21 by lcabanes          #+#    #+#             */
/*   Updated: 2019/01/19 02:31:37 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_nb *stacks[2], char c)
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
