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
**     (char *)(*line)
** 'li_allocate_room'
**     (t_room *)*room : data->rooms (liste chainee)
** 'li_allocate_map'
**     (t_room **)data->map
**     (signed char *)set_map : (*(data->map + 0))->pipes
** 'li_shorten_map_pipes'
**     (size_t *)(*(data->map + 0))->bond_sum
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

void	li_memory_liberator(t_data *data)
{
	(void)data;
}
