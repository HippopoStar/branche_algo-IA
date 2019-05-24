/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:54:29 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/24 15:21:44 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Cas 1 :
** 1
** 2
** 3
** Cas 2 :
** 1
** 3
** 2
** Cas 3 :
** 2
** 1
** 3
** Cas 4 :
** 2
** 3
** 1
** Cas 5 :
** 3
** 1
** 2
** Cas 6 :
** 3
** 2
** 1
*/

void	ps_sort_three(t_ps *data)
{
	int		first;
	int		second;
	int		third;

	first = (*(data->stacks + 0))->nb;
	second = ((*(data->stacks + 0))->next)->nb;
	third = (((*(data->stacks + 0))->next)->next)->nb;
	if (first < third && third < second)
	{
		ps_print_and_do(data, "sa");
		ps_print_and_do(data, "ra");
	}
	else if (second < first && first < third)
		ps_print_and_do(data, "sa");
	else if (third < first && first < second)
		ps_print_and_do(data, "rra");
	else if (second < third && third < first)
		ps_print_and_do(data, "ra");
	else if (third < second && second < first)
	{
		ps_print_and_do(data, "ra");
		ps_print_and_do(data, "sa");
	}
}
