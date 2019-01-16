/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:29:10 by lcabanes          #+#    #+#             */
/*   Updated: 2019/01/16 19:29:11 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_nb *stacks[2], char c)
{
	t_nb	*stack;
	t_nb	*tmp;

	stack = *(stacks + (c - 'a'));
	if (stack != NULL && (tmp = stack->next) != NULL)
	{
		while (stack->next != NULL)
		{
			stack = stack->next;
		}
		stack->next = *(stacks + (c - 'a'));
		(*(stacks + (c - 'a')))->next = NULL;
		*(stacks + (c - 'a')) = tmp;
	}
}
