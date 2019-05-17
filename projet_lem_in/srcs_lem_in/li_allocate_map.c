/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_allocate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:32:51 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/17 17:32:59 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		aux_li_allocate_map(t_data *data, int *set_map)
{
	size_t	i;
	t_room	*tmp;

	i = 1;
	tmp = data->rooms;
	while (tmp->role != 5)
	{
		if (tmp->role == 1)
		{
			*(data->map + i) = tmp;
			(*tmp).pipes = &(*(set_map + (i * data->size)));
			i++;
		}
		else if (tmp->role == 2)
		{
			*(data->map + 0) = tmp;
			(*tmp).pipes = &(*(set_map + 0));
		}
		else
		{
			*(data->map + data->size - 1) = tmp;
			(*tmp).pipes = &(*(set_map + ((data->size - 1) * data->size)));
		}
		tmp = tmp->next;
	}
	return ((i == data->size - 1) ? 1 : 0);
}

int		li_allocate_map(t_data *data)
{
	size_t	i;
	t_room	*tmp;
	int		*set_map;

	i = 0;
	tmp = data->rooms;
	while (tmp->role != 5)
	{
		tmp = tmp->next;
		i++;
	}
	data->size = i;
	if (!(data->map = (t_room **)malloc(i * sizeof(t_room *)))
			|| !(set_map = (int *)malloc(i * i * sizeof(int))))
		return (0);
	i = 0;
	while (i < data->size * data->size)
	{
		*(set_map + i) = 0;
		i++;
	}
	return (aux_li_allocate_map(data, set_map));
}
