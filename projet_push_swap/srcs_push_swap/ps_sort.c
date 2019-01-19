/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 02:14:32 by lcabanes          #+#    #+#             */
/*   Updated: 2019/01/19 05:24:58 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_aux_distribute(t_ps *data, size_t start, size_t end, char c)
{
	t_nb	*tmp;
	int		pivot;
	size_t	i;

	tmp = ((c == 'a') ? *(data->stacks + 0) : *(data->stacks + 1));
	pivot = *(data->sorted + ((start + end) / 2));
	i = 0;
	while (tmp != NULL && (*(data->sorted + start) <= tmp->nb && tmp->nb <= *(data->sorted + end)) && i <= (end - start))
	{
		if (tmp->nb < pivot)
		{
			(c == 'a') ? ps_print_and_apply(data, "pb") : ps_print_and_apply(data, "rb");
		}
		else
		{
			(c == 'a') ? ps_print_and_apply(data, "ra") : ps_print_and_apply(data, "pa");
		}
		tmp = ((c == 'a') ? *(data->stacks + 0) : *(data->stacks + 1));
		i++;
	}
}

void	ps_distribute(t_ps *data, size_t start, size_t end, char c)
{
	ps_aux_distribute(data, start, end, c);
}

void	ps_aux_sort(t_ps *data, size_t start, size_t end, size_t occ)
{
	if (ps_are_sorted(data))
	{
		while (*(data->stacks + 1) != NULL)
		{
			ps_print_and_apply(data, "pa");
		}
	}
	else
	{
		ps_distribute(data, start, end, ((occ % 2) == 0 ? 'a' : 'b'));
	}
}

void	ps_sort(t_ps *data)
{
	ps_aux_sort(data, 0, data->length - 1, 0);
}
