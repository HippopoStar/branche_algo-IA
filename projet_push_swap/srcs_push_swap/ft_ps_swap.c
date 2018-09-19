/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:40:54 by lcabanes          #+#    #+#             */
/*   Updated: 2018/09/19 11:40:56 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_swap(t_nb **stacks, char c)
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
