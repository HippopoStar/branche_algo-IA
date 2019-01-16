/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:27:36 by lcabanes          #+#    #+#             */
/*   Updated: 2019/01/16 19:28:45 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_nb *stacks[2], char c)
{
	t_nb	*stack;
	t_nb	*tmp;

	stack = *(stacks + (c - 'a'));
	if (stack != NULL && stack->next != NULL)
	{
		tmp = stack->next;
		stack->next = (stack->next)->next;
		tmp->next = stack;
		*(stacks + (c - 'a')) = tmp;
	}
}
