/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_is_ready_to_go.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 03:23:50 by lcabanes          #+#    #+#             */
/*   Updated: 2019/02/09 16:29:01 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_is_b_sorted(t_ps *data)
{
	t_nb	*tmp;
	size_t	i;

	tmp = *(data->stacks + 1);
	i = 0;
	if (tmp != NULL)
	{
		while (tmp->nb != *(data->sorted + i))
		{
			i++;
		}
		while (tmp != NULL && tmp->next != NULL && i > 0 \
				&& tmp->nb == *(data->sorted + i))
		{
			tmp = tmp->next;
			i--;
		}
		return ((tmp->next == NULL && i == 0 \
					&& tmp->nb == *(data->sorted + 0)) ? 1 : 0);
	}
	return (1);
}

int		ps_is_a_sorted(t_ps *data)
{
	t_nb	*tmp;
	size_t	i;

	tmp = *(data->stacks + 0);
	i = 0;
	if (tmp != NULL)
	{
		while (tmp->nb != *(data->sorted + i))
		{
			i++;
		}
		while (tmp != NULL && i < data->length
				&& tmp->nb == *(data->sorted + i))
		{
			tmp = tmp->next;
			i++;
		}
		return ((tmp == NULL && i == data->length) ? 1 : 0);
	}
	return (1);
}

int		ps_are_sorted(t_ps *data)
{
	return ((ps_is_a_sorted(data) && ps_is_b_sorted(data)) ? 1 : 0);
}

int		ps_is_ready_to_go(t_ps *data)
{
	return ((ps_is_a_sorted(data) && *(data->stacks + 1) == NULL) ? 1 : 0);
}
