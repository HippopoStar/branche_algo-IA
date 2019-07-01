/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_move_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:49:03 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/11 19:56:08 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Allocation dynamique de memoire dans 'li_allocate_ant_tab'
** (t_ant *)data->ant_tab
*/

int		li_allocate_ant_tab(t_data *data)
{
	size_t	i;

	if (!(data->ant_tab = (t_ant *)malloc(data->ants * sizeof(t_ant))))
		return (0);
	i = 0;
	while (i < (size_t)data->ants)
	{
		(*(data->ant_tab + i)).pos_y = 0;
		(*(data->ant_tab + i)).wait = 0;
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
** ant_y = ant_id % (data->best_route + 1);
** ant_x = (i / data->ants) - (ant_y % (data->ants + 1));
** room_id = *(*(*(data->routes + data->best_route) + ant_y) + ant_x);
** room_name = (*(data->map + room_id))->name;
**
** Affichage lorsque :
** 0 < ant_x < data->size
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

void	li_ants_distribution(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	ord;

	i = 0;
	j = 0;
	while (i < (size_t)data->ants)
	{
		ord = j % (data->best_route + 1);
		if (*(*(*(data->routes + data->best_route) + ord) + data->size + 1) > 0)
		{
			(*(data->ant_tab + i)).pos_y = ord;
			(*(data->ant_tab + i)).wait = j / (data->best_route + 1);
			(*(*(*(data->routes + data->best_route) + ord) + data->size + 1))--;
			i++;
		}
		j++;
	}
}

/*
** On peut vouloir ajouter la ligne suivante a la suite des appels
** de 'li_get_output' :
**				li_print_output(data);
*/

void	aux_li_move_ants(t_data *data, size_t step)
{
	size_t	i;
	size_t	abs;
	size_t	wit;

	wit = 1;
	i = 0;
	while (i < (size_t)data->ants)
	{
		if ((*(data->ant_tab + i)).wait < step)
		{
			abs = step - (*(data->ant_tab + i)).wait;
			if (abs < *(*(*(data->routes + data->best_route)
							+ (*(data->ant_tab + i)).pos_y) + data->size))
			{
				li_get_output(data, &(*((*(data->ant_tab + i)).to_print
								+ wit)));
				li_get_output(data, (*(data->map
								+ *(*(*(data->routes + data->best_route)
										+ (*(data->ant_tab + i)).pos_y)
									+ abs)))->name);
				wit = 0;
			}
		}
		i++;
	}
}

int		li_move_ants(t_data *data)
{
	char	to_display[28];
	size_t	i;

	if (!(li_allocate_ant_tab(data)))
		return (0);
	if ((data->display_steps = li_steps_length(data)) > 0)
	{
		li_prepare_steps_str(data, to_display);
	}
	li_ants_distribution(data);
	i = 1;
	while (i <= data->best_steps)
	{
		if (data->display_steps > 0)
		{
			li_display_steps(data, i, to_display);
			li_get_output(data, (char *)to_display);
		}
		aux_li_move_ants(data, i);
		li_get_output(data, "\n");
		i++;
	}
	return (1);
}
