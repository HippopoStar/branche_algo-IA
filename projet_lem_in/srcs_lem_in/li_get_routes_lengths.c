/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_get_routes_lengths.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:38:11 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/19 18:22:13 by lcabanes         ###   ########.fr       */
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

/*
** Etant donne qu'il ne faut pas modifier les positions des salles de depart
** et d'arrive, dans le cas ou on a un total de 2 ou 3 salles, il n'y a rien
** a trier
*/

void	li_order_rooms(t_data *data)
{
	t_room	*tmp;
	size_t	i;

	i = 2;
	while (i < data->size - 1)
	{
		while (i > 1 && (*(data->map + i - 1))->weight
				> (*(data->map + i))->weight)
		{
			tmp = *(data->map + i - 1);
			*(data->map + i - 1) = *(data->map + i);
			*(data->map + i) = tmp;
			i--;
		}
		i++;
	}
}
