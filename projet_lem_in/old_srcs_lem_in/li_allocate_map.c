/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_allocate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:32:51 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/12 18:24:39 by lcabanes         ###   ########.fr       */
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
**
** Concernant la liberation de la memoire :
** Prendre des precautions :
** l'allocation de 'data->map' peut reussir
** et celle de 'set_map' echouer
**
** Dans ce cas, '(*(data->map + 0))->pipes' n'est pas assignee
** La seule maniere securisee de liberer la memoire alloue pour
** la carte est de passer par '(t_room *) && (t_room *)->role == 2'
** dans la liste chainee 'data->rooms'
*/

int		li_allocate_map(t_data *data)
{
	size_t		i;
	size_t		square;
	signed char	*set_map;

	square = data->size * data->size;
	if (!(data->map = (t_room **)malloc(data->size * sizeof(t_room *)))
			|| !(set_map = (signed char *)malloc(square * sizeof(signed char))))
		return (0);
	i = 0;
	while (i < square)
	{
		*(set_map + i) = (signed char)0;
		i++;
	}
	return (aux_li_allocate_map(data, set_map));
}
