/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_order_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:19:19 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/16 16:19:21 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** On ne peut pas depasser les tableaux dans un sens ni dans l'autre,
** car on sait que chaque tableau commence par '0', correspondant a
** la 1ere salle, et se termine par 'data->size', correspondant a la derniere
** salle (au plus tard en position 'data->size - 1')
*/

void	li_swap_paths(t_route *route, size_t i, size_t j)
{
	size_t	*tmp;

	tmp = *(route->field + i);
	*(route->field + i) = *(route->field + j);
	*(route->field + j) = tmp;
}

void	li_order_paths(t_route *route)
{
	size_t	*tmp;
	size_t	i;

	i = 1;
	while (i <= route->height)
	{
		while (*(*(route->field + i - 1) + route->width)
				> *(*(route->field + i) + route->width) && i > 0)
		{
			tmp = *(route->field + i - 1);
			*(route->field + i - 1) = *(route->field + i);
			*(route->field + i) = tmp;
			i--;
		}
		i++;
	}
}
