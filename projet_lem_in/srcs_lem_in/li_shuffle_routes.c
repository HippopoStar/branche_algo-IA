/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_shuffle_routes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 19:33:45 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/02 21:11:34 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** On ne peut pas depasser les tableaux dans un sens ni dans l'autre,
** car on sait que chaque tableau commence par '0', correspondant a
** la 1ere salle, et se termine par 'data->size', correspondant a la derniere
** salle (au plus tard en position 'data->size - 1')
*/

size_t	li_get_inversed_edge_gap(size_t *a, size_t *b, size_t *i, size_t *j)
{
	size_t	gap;

	gap = 1;
	while (*(i + (*j) - 1) == *(a + (*b) + 1))
	{
		(*j)--;
		(*b)++;
		gap++;
	}
	return (gap);
}

//void	li_remove_inversed_edge(t_data *data, size_t **field, size_t ref_a[2], size_t ref_i[2])
//void	li_shuffle_routes(t_data *data, )
