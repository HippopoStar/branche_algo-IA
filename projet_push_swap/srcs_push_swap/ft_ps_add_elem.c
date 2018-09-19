/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_add_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:41:34 by lcabanes          #+#    #+#             */
/*   Updated: 2018/09/19 11:41:36 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_add_elem(t_nb **stacks, char c, int nb)
{
	t_nb	*tmp;

	if (!(tmp = (t_nb *)malloc(sizeof(t_nb))))
		exit(-1);
	tmp->n = nb;
	tmp->next = *(stacks + (c - 'a'));
	*(stacks + (c - 'a')) = tmp;
}
