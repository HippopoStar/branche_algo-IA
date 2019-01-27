/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_gotta_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:50:50 by lcabanes          #+#    #+#             */
/*   Updated: 2019/01/23 13:05:55 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_gotta_push(t_nb *tmp, int pivot, char c)
{
	while (tmp != NULL)
	{
		if ((c == 'a') ? tmp->nb <= pivot : pivot <= tmp->nb)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
