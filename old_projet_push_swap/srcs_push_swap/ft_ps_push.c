/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:40:44 by lcabanes          #+#    #+#             */
/*   Updated: 2018/10/11 16:23:02 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_push(t_nb *stacks[2], char c)
{
	t_nb	*tmp;

	tmp = *(stacks + ((c - 'a' + 1) % 2));
	if (tmp != NULL)
	{
		*(stacks + ((c - 'a' + 1) % 2)) = tmp->next;
		tmp->next = *(stacks + (c - 'a'));
		*(stacks + (c - 'a')) = tmp;
	}
}
