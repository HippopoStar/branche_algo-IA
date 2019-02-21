/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_shorten.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 12:44:36 by lcabanes          #+#    #+#             */
/*   Updated: 2019/02/21 13:13:54 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_aux_shorten(char first[4], char second[4])
{
	return (((!ft_strcmp(first, "sa") && !ft_strcmp(second, "sa"))
				|| (!ft_strcmp(first, "sb") && !ft_strcmp(second, "sb"))
				|| (!ft_strcmp(first, "ss") && !ft_strcmp(second, "ss"))
				|| (!ft_strcmp(first, "pa") && !ft_strcmp(second, "pb"))
				|| (!ft_strcmp(first, "pb") && !ft_strcmp(second, "pa"))
				|| (!ft_strcmp(first, "ra") && !ft_strcmp(second, "rra"))
				|| (!ft_strcmp(first, "rb") && !ft_strcmp(second, "rrb"))
				|| (!ft_strcmp(first, "rr") && !ft_strcmp(second, "rrr"))
				|| (!ft_strcmp(first, "rra") && !ft_strcmp(second, "ra"))
				|| (!ft_strcmp(first, "rrb") && !ft_strcmp(second, "rb"))
				|| (!ft_strcmp(first, "rrr") && !ft_strcmp(second, "rr"))) ? 1 \
			: 0);
}

void	ps_shorten(t_input **input)
{
	t_input	*tmp;
	t_input	*follow;
	int		wit;

	wit = 1;
	while ((*input) != NULL && (*input)->next != NULL \
			&& ((*input)->next)->next != NULL && wit == 1)
	{
		wit = 0;
		tmp = *input;
		while (tmp != NULL && tmp->next != NULL && (tmp->next)->next != NULL)
		{
			if (ps_aux_shorten((tmp->next)->inst, ((tmp->next)->next)->inst))
			{
				follow = ((tmp->next)->next)->next;
				free((tmp->next)->next);
				free(tmp->next);
				tmp->next = follow;
				wit = 1;
			}
			else
				tmp = tmp->next;
		}
	}
}
