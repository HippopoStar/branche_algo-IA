/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_liberate_stacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 23:02:30 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/23 23:12:41 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_liberate_stacks(t_nb *stacks[2])
{
	t_nb	*tmp_stack;

	while (*(stacks + 0) != NULL)
	{
		tmp_stack = (*(stacks + 0))->next;
		free(*(stacks + 0));
		*(stacks + 0) = tmp_stack;
	}
	while (*(stacks + 1) != NULL)
	{
		tmp_stack = (*(stacks + 1))->next;
		free(*(stacks + 1));
		*(stacks + 1) = tmp_stack;
	}
}
