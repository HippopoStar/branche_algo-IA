/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_move_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:49:03 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/30 19:14:04 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		li_allocate_ant_tab(t_data *data)
{
	size_t	i;

	if (!(data->ant_tab = (t_ant *)malloc(data->ants * sizeof(t_ant))))
		return (0);
	i = 0;
	while (i < (size_t)data->ants)
	{
		(*(data->ant_tab + i)).pos_x = i % (data->best_route + 1);
		(*(data->ant_tab + i)).pos_y = 1;
		li_size_ttoa(i + 1, (*(data->ant_tab + i)).to_print, data->color);
		i++;
	}
	return (1);
}

/*
** En prenant comme reference dans le deplacement des fourmis un index 'i'
** prenant comme valeur de depart '0' et en l'incrementant jusqu'a
** 'data->best_steps * (size_t)data->ants', pour chaque valeur de 'i', on a :
**
** ant_id = i % (size_t)data->ants;
** ant_x = ant_id % (data->best_route + 1);
** ant_y = (i / data->best_route); //TODO -------------------------------------
** room_id = *(*(*(data->routes + data->best_route) + ant_x) + ant_y);
** room_name = (*(data->map + room_id))->name;
**
** Affichage lorsque :
** 0 < ant_y < data->size
** 0 < room_id
**
** 4 itineraires : 8 fourmis
** i = 0 : 1
** i = 1 : 1
** i = 2 : 1
** i = 3 : 1
** i = 4 : 0
** i = 5 : 0
** i = 6 : 0
** i = 7 : 0
*/

void	aux_li_move_ants(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < (size_t)data->ants && (*(data->ant_tab + i)).pos_y != 1)
	{
		if ((*(data->ant_tab + i)).pos_y < *(*(*(data->routes + data->best_route) + (*(data->ant_tab + i)).pos_x) + data->size))
		{
			li_get_output(data, (char *)(*(data->ant_tab + i)).to_print);
			li_get_output(data, (*(data->map + *(*(*(data->routes + data->best_route) + (*(data->ant_tab + i)).pos_x) + (*(data->ant_tab + i)).pos_y)))->name);
			((*(data->ant_tab + i)).pos_y)++;
		}
		i++;
	}
	j = 0;
	while (j <= data->best_route && i + j < (size_t)data->ants)
	{
		li_get_output(data, (char *)(*(data->ant_tab + i + j)).to_print);
		li_get_output(data, (*(data->map + *(*(*(data->routes + data->best_route) + (*(data->ant_tab + i + j)).pos_x) + (*(data->ant_tab + i + j)).pos_y)))->name);
		((*(data->ant_tab + i + j)).pos_y)++;
		j++;
	}
}

int		li_move_ants(t_data *data)
{
//	size_t	calls;
	size_t	i;
//	size_t	j;

	if (!(li_allocate_ant_tab(data)))
		return (0);
	i = 1;
	while (i <= data->best_steps)
	{
//		calls = i * (data->best_index + 1);
//		j = 0;
//		while (j < calls)
//		{
			aux_li_move_ants(data);
			li_get_output(data, "\n");
//			j++;
//		}
		i++;
	}
	return (1);
}
