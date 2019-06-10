/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_bellman_ford.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:33:06 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/05 21:04:55 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	aux_li_bellman_ford(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	target;
	int		wei;

	i = 0;
	while (i < data->size)
	{
		j = 0;
		while (j < (*(data->map + i))->nb_of_bonds)
		{
			target = *((*(data->map + i))->bond_sum + j);
			if (*((*(data->map + i))->pipes + target) != 0 && i != target)
			{
				wei = (*(data->map + i))->weight
					+ (int)(*((*(data->map + i))->pipes + target));
				if (wei < (*(data->map + target))->weight)
				{
					(*(data->map + target))->ancestor = i;
					(*(data->map + target))->weight = wei;
				}
			}
			j++;
		}
		i++;
	}
}

void	li_bellman_ford(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->size)
	{
		aux_li_bellman_ford(data);
		i++;
	}
}
