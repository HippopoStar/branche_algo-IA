/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_move_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:49:03 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/28 16:26:22 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Allocation dynamique de memoire dans 'aux_li_move_ants' ('ft_itoa')
** / ! \ Penser a la gestion d'erreur
*/

void	aux_li_move_ants(t_data *data, size_t j)
{
	size_t	ant_id;
	size_t	room_id;
	char	*ant_name;

	room_id = *(*(*(data->routes + data->best_route) + (j % data->path_nb))
			+ (j / data->path_nb));
	ant_id = j % data->size;
	ant_name = ft_itoa((int)ant_id);
	li_get_output(data, "L");
	li_get_output(data, ant_name);
	free(ant_name);
	li_get_output(data, "-");
	li_get_output(data, (*(data->rooms + room_id)).name);
	li_get_output(data, " ");
}

void	li_move_ants(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < data->best_steps)
	{
		while (j % data->size > 0)
		{
			aux_li_move_ants(data, j);
			j++;
		}
		i++;
	}
}

