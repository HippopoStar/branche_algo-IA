/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 07:19:51 by lcabanes          #+#    #+#             */
/*   Updated: 2018/10/09 07:25:32 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_free_lst(t_nb *lst)
{
	t_nb	*tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	ft_ps_free_stacks(t_nb **stacks)
{
	ft_ps_free_lst(*(stacks + 0));
	ft_ps_free_lst(*(stacks + 1));
	free(stacks);
}
