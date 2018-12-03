/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_check_doublons.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:35:45 by lcabanes          #+#    #+#             */
/*   Updated: 2018/10/11 17:31:35 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_ps_check_doublons(t_nb *sorted_lst)
{
	t_nb	*tmp;

	tmp = sorted_lst;
	while (tmp->next != NULL)
	{
		if (tmp->n == (tmp->next)->n)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	ft_ps_checker_programm_check_doublons(t_nb *stack_a)
{
	t_nb	*sorted_lst;

	sorted_lst = ft_ps_get_refs(stack_a, 0);
	if (ft_ps_check_doublons(sorted_lst) == 1)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	ft_ps_free_lst(sorted_lst);
}
