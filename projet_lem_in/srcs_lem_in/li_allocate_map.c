/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_allocate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:32:51 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/11 20:20:37 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		aux_li_allocate_map(t_data *data, signed char *set_map)
{
	size_t	i;
	t_room	*tmp;
	size_t	first_or_last;

	i = 1;
	tmp = data->rooms;
	while (tmp != NULL)
	{
		if (tmp->role == 1)
		{
			*(data->map + i) = tmp;
			(*tmp).pipes = &(*(set_map + (i * data->size)));
			i++;
		}
		else
		{
			first_or_last = (tmp->role == 2) ? 0 : data->size - 1;
			*(data->map + first_or_last) = tmp;
			(*tmp).pipes = &(*(set_map + (first_or_last * data->size)));
		}
		tmp = tmp->next;
	}
	return ((i == data->size - 1) ? 1 : 0);
}

/*
** Allocation dynamique de memoire dans 'li_allocate_map'
** (t_room **)data->map
** (signed char *)set_map : (*(data->map + 0))->pipes
*/

int		li_allocate_map(t_data *data)
{
	size_t		i;
	t_room		*tmp;
	signed char	*set_map;

	i = 0;
	tmp = data->rooms;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	data->size = i;
	if (!(data->map = (t_room **)malloc(i * sizeof(t_room *)))
			|| !(set_map = (signed char *)malloc(i * i * sizeof(signed char))))
		return (0);
	i = 0;
	while (i < data->size * data->size)
	{
		*(set_map + i) = (signed char)0;
		i++;
	}
	return (aux_li_allocate_map(data, set_map));
}
