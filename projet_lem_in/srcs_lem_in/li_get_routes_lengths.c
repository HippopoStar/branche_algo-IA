/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_get_routes_lengths.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:38:11 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/28 19:47:18 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Cette fonction est caduque
** car on calcul en place
** la longueur de chaque itineraire
** lors de l'execution de chaque algo
** pouvant l'alterer
*/

void	li_get_routes_lengths(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (i < data->path_nb)
	{
		j = 0;
		while (j <= i)
		{
			k = 1;
			while (*(*(*(data->routes + i) + j) + k) != 0 && k < data->size)
			{
				k++;
			}
			*(*(*(data->routes + i) + j) + data->size) = k;
			j++;
		}
		i++;
	}
}
