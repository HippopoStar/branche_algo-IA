/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:51:19 by lcabanes          #+#    #+#             */
/*   Updated: 2019/02/09 16:41:50 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	ft_putstr("stack: ");					//TODO
**	ft_putchar((c == 'a') ? 'A' : 'B');		//TODO
**	ft_putchar('\n');						//TODO
**	ft_putstr("start: ");					//TODO
**	ft_putnbr(*(data->sorted + start));		//TODO
**	ft_putchar('\n');						//TODO
**	ft_putstr("end: ");						//TODO
**	ft_putnbr(*(data->sorted + end));		//TODO
**	ft_putchar('\n');						//TODO
**	ft_putstr("pivot: ");					//TODO
**	ft_putnbr(pivot);						//TODO
**	ft_putchar('\n');						//TODO
*/

void	ps_distribute(t_ps *data, size_t start, size_t end, char c)
{
	t_nb	*tmp;
	int		pivot;
	int		wit;

	tmp = ((c == 'a') ? *(data->stacks + 0) : *(data->stacks + 1));
	pivot = *(data->sorted + ((start + end + 1) / 2));
	wit = 0;
	while (tmp != NULL && tmp->next != NULL \
			&& !((c == 'a') ? ps_is_a_sorted(data) : ps_is_b_sorted(data)) \
			&& (ps_gotta_push(tmp, pivot, c) || tmp->next->next == NULL))
	{
		if (tmp->nb == pivot)
		{
			(c == 'a') ? ps_print_ando(data, "pb") : ps_print_ando(data, "pa");
			(c == 'a') ? ps_print_ando(data, "rb") : ps_print_ando(data, "ra");
			wit = 1;
		}
		else if (tmp->nb < pivot)
			(c == 'a') ? ps_print_ando(data, "pb") : ps_print_ando(data, "rb");
		else
			(c == 'a') ? ps_print_ando(data, "ra") : ps_print_ando(data, "pa");
		tmp = ((c == 'a') ? *(data->stacks + 0) : *(data->stacks + 1));
	}
	if (wit == 1)
		(c == 'a') ? ps_print_ando(data, "rrb") : ps_print_ando(data, "rra");
}

void	ps_aux_sort_five(t_ps *data, size_t start, size_t end, size_t *occ)
{
	(*occ)++;
	if (ps_are_sorted(data))
	{
		while (*(data->stacks + 1) != NULL)
		{
			ps_print_ando(data, "pa");
		}
	}
	else if ((end - start) > 2)
	{
		ps_distribute(data, start, end, (((*occ) % 2) == 0 ? 'a' : 'b'));
		ps_aux_sort_five(data, start, (start + end + 1) / 2, occ);
		ps_aux_sort_five(data, (start + end - 1) / 2, end, occ);
	}
	else if ((end - start) > 1)
	{
		ps_distribute(data, start, end, (((*occ) % 2) == 0 ? 'a' : 'b'));
	}
}

void	ps_sort_five(t_ps *data)
{
	size_t	occ;

	occ = 1;
	ps_aux_sort_five(data, 0, data->length - 1, &occ);
}
