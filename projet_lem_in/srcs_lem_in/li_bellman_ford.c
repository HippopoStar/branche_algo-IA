/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_bellman_ford.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:33:06 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/17 17:36:50 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	aux_li_bellman_ford(t_data *data)
{
	size_t	i;
	size_t	j;
	int		wei;

	i = 0;
	while (i < data->size)
	{
		j = 0;
		while (j < data->size)
		{
			if (*((*(data->map + i))->pipes + j) != 0 && i != j)
			{
				wei = (*(data->map + i))->weight \
					+ *((*(data->map + i))->pipes + j);
				if (wei < (*(data->map + j))->weight)
				{
					(*(data->map + j))->ancestor = i;
					(*(data->map + j))->weight = wei;
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
