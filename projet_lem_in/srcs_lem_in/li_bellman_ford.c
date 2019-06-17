/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_bellman_ford.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:33:06 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/17 16:52:19 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Si on a atteint la salle suivante
** (en lui ayant decouvert un nouveau poids minimum)
** en passant par une liaison de poids positif,
** on place la valeur de sa variable 'except' sur '0',
** en revanche si on l'a atteinte en passant par une liaison de poids negatif,
** on place la valeur de sa variable 'except' sur '1'
**
** (Notez qu'on ne peut atteindre de salle en passant par une liaison
** de poids nul)
*/

void	li_ping_neighbour(t_data *data, size_t i, size_t j)
{
	size_t	target;
	int		wei;

	target = *((*(data->map + i))->bond_sum + j);
	if (*((*(data->map + i))->pipes + target) != 0 && i != target
			&& ((wei = (*(data->map + i))->weight
					+ (int)(*((*(data->map + i))->pipes + target)))
				< (*(data->map + target))->weight))
	{
		(*(data->map + target))->ancestor = i;
		(*(data->map + target))->weight = wei;
		(*(data->map + target))->except = *((*(data->map + i))->pipes + target)
			== (signed char)1 ? 0 : 1;
	}
}

void	aux_li_bellman_ford(t_data *data, size_t i)
{
	size_t	j;
	size_t	target;

	j = 0;
	if (!((*(data->map + i))->allowed || (*(data->map + i))->except))
	{
		while (j < (*(data->map + i))->nb_of_bonds)
		{
			target = *((*(data->map + i))->bond_sum + j);
			if (*((*(data->map + i))->pipes + target) == (signed char)(-1))
			{
				li_ping_neighbour(data, i, j);
			}
			j++;
		}
	}
	else
	{
		while (j < (*(data->map + i))->nb_of_bonds)
		{
			target = *((*(data->map + i))->bond_sum + j);
			li_ping_neighbour(data, i, j);
			j++;
		}
	}
}

void	li_bellman_ford(t_data *data)
{
	size_t	iteration;
	size_t	i;

	iteration = 0;
	while (iteration < data->size)
	{
		i = 0;
		while (i < data->size)
		{
			aux_li_bellman_ford(data, i);
			i++;
		}
		iteration++;
	}
}
