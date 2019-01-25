/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 02:14:32 by lcabanes          #+#    #+#             */
/*   Updated: 2019/01/25 17:08:15 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_aux_distribute(t_ps *data, size_t start, size_t end, char c)
{
	t_nb	*tmp;
	int		pivot;

//	ft_putstr("ps_aux_distribute\n");		//TODO
	tmp = ((c == 'a') ? *(data->stacks + 0) : *(data->stacks + 1));
	pivot = *(data->sorted + ((start + end + 1) / 2));
/*
	ft_putstr("stack: ");					//TODO
	ft_putchar((c == 'a') ? 'A' : 'B');		//TODO
	ft_putchar('\n');						//TODO
	ft_putstr("start: ");					//TODO
	ft_putnbr(*(data->sorted + start));		//TODO
	ft_putchar('\n');						//TODO
	ft_putstr("end: ");						//TODO
	ft_putnbr(*(data->sorted + end));		//TODO
	ft_putchar('\n');						//TODO
	ft_putstr("pivot: ");					//TODO
	ft_putnbr(pivot);						//TODO
	ft_putchar('\n');						//TODO
*/
	while (tmp != NULL && tmp->next != NULL && !((c == 'a') ? ps_is_a_sorted(data) : ps_is_b_sorted(data)) && (ps_gotta_push(tmp, pivot, c) || tmp->next->next == NULL))
	{
		if (tmp->nb < pivot)
		{
			(c == 'a') ? ps_print_and_apply(data, "pb") : ps_print_and_apply(data, "rb");
		}
		else
		{
			(c == 'a') ? ps_print_and_apply(data, "ra") : ps_print_and_apply(data, "pa");
		}
//		ps_display_stacks(data->stacks);	//TODO
		tmp = ((c == 'a') ? *(data->stacks + 0) : *(data->stacks + 1));
	}
}

void	ps_distribute(t_ps *data, size_t start, size_t end, char c)
{
//	ft_putstr("ps_distribute\n");			//TODO
	ps_aux_distribute(data, start, end, c);
}

void	ps_aux_sort(t_ps *data, size_t start, size_t end, size_t *occ)
{
//	ft_putstr("ps_aux_sort\n");				//TODO
	(*occ)++;
	if (ps_are_sorted(data))
	{
		while (*(data->stacks + 1) != NULL)
		{
			ps_print_and_apply(data, "pa");
		}
	}
	else if ((end - start) > 2)
	{
		ps_distribute(data, start, end, (((*occ) % 2) == 0 ? 'a' : 'b'));
		ps_aux_sort(data, start, (start + (3 * end) - 1) / 4, occ);
		ps_aux_sort(data, ((3 * start) + end + 1) / 4, end, occ);
	}
	else if ((end - start) > 0)
	{
		ps_distribute(data, start, end, (((*occ) % 2) == 0 ? 'a' : 'b'));
		ps_aux_sort(data, start, (start + end - 1) / 2, occ);
		ps_aux_sort(data, (start + end + 1) / 2, end, occ);
	}
}

void	ps_sort(t_ps *data)
{
	size_t	occ;

//	ft_putstr("ps_sort\n");					//TODO
//	ps_display_stacks(data->stacks);		//TODO
	occ = 0;
	ps_aux_sort(data, 0, data->length - 1, &occ);
//	ps_display_stacks(data->stacks);		//TODO
}
