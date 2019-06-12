/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_memory_liberator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 22:34:38 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/11 20:22:27 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Sommaire des allocations dynamiques de memoire :
** 'li_get_next_non_comment_line'
**     (char *)(*line) / ! \
** 'li_allocate_room'
**     (t_room *)*room : data->rooms (liste chainee)
** 'li_allocate_map'
**     (t_room **)data->map
**     (signed char *)set_map : (*(data->map + 0))->pipes / ! \
** 'li_shorten_map_pipes'
**     (size_t *)(*(data->map + 0))->bond_sum / ! \
** 'li_allocate_paths'
**     (size_t **)data->paths
**     (size_t *)*(data->paths + 0)
** 'li_allocate_routes'
**     (size_t ***)data->routes
**     (size_t **)*(data->routes + 0)
**     (size_t *)*(*(data->routes + 0) + 0)
** 'li_allocate_ant_tab'
**     (t_ant *)data->ant_tab
*/
/*
** 'data->rooms' est initialisee a 'NULL' dans 'main'
** '(t_room *)->name' est initialisee a 'NULL' dans 'li_allocate_room'
** '(t_room *)->pipes' est initialisee a 'NULL' dans 'li_allocate_room'
** '(t_room *)->bond_sum' est initialisee a 'NULL' dans 'li_allocate_room'
*/

void	li_liberate_rooms_map_and_bonds(t_data *data)
{
	t_room	*tmp;

	while (data->rooms)
	{
		tmp = (data->rooms)->next;
		if ((data->rooms)->role == 2)
		{
			if ((data->rooms)->pipes)
			{
				free((data->rooms)->pipes);
			}
			if ((data->rooms)->bond_sum)
			{
				free((data->rooms)->bond_sum);
			}
		}
		if ((data->rooms)->name)
		{
			free((data->rooms)->name);
		}
		free(data->rooms);
		data->rooms = tmp;
	}
}

void	li_liberate_paths_and_routes(t_data *data)
{
	if (data->paths)
	{
		if (*(data->paths + 0))
		{
			free(*(data->paths + 0));
		}
		free(data->paths);
	}
	if (data->routes)
	{
		if (*(data->routes + 0))
		{
			if (*(*(data->routes + 0) + 0))
			{
				free(*(*(data->routes + 0) + 0));
			}
			free(*(data->routes + 0));
		}
		free(data->routes);
	}
}

void	li_memory_liberator(t_data *data)
{
	li_liberate_rooms_map_and_bonds(data);
	if (data->map)
	{
		free(data->map);
	}
	li_liberate_paths_and_routes(data);
	if (data->ant_tab)
	{
		free(data->ant_tab);
	}
}
