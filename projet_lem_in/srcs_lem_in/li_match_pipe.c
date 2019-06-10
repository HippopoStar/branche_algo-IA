/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_match_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:53:22 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/10 21:36:35 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		li_actualise_map(t_data *data, size_t i, size_t j)
{
	if (*((*(data->map + i))->pipes + j) == 1
			|| *((*(data->map + j))->pipes + i) == 1)
	{
		return (0);
	}
	else
	{
		*((*(data->map + i))->pipes + j) = 1;
		*((*(data->map + j))->pipes + i) = 1;
		((*(data->map + i))->nb_of_bonds)++;
		((*(data->map + j))->nb_of_bonds)++;
		return (1);
	}
}

/*
** La fonction 'li_match_pipe'
** va rechercher les index respectifs des deux salles
** dans le tableau 'data->map'
** et ajouter a chacune la liaison correspondante dans leur liste
** les repertoriant '(t_room *)->pipes'
**
** Au passage, elle comptabilise le nombre total de liaisons
** dans la variable 'data->bonds'
** (initialisee a '0' dans la fonction 'li_match_pipes')
** Et met a jour les valeurs respectives de '(t_room *)->nb_of_bonds'
** (initialisees a '0' dans la fonction 'li_allocate_room')
**
** / ! \ Faut-il ici renvoyer une erreur dans le cas dans lequel la
** liaison a deja ete repertoriee anterieurement (doublon) ?
*/

int		li_match_pipe(t_data *data, char *line)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	while (*(line + i) != '-' && *(line + i) != '\0')
	{
		i++;
	}
	tmp = (*(line + i) == '-') ? (line + i + 1) : (line + i);
	*(line + i) = '\0';
	i = 0;
	while (i < data->size && ft_strcmp((*(data->map + i))->name, line))
	{
		i++;
	}
	j = 0;
	while (j < data->size && ft_strcmp((*(data->map + j))->name, tmp))
	{
		j++;
	}
	if (i == data->size || j == data->size || i == j)
		return (0);
	return (li_actualise_map(data, i, j));
}

/*
** Etant donne le comportement et les conditions de validite de
** 'li_match_rooms' dont l'appel precede celui de 'li_match_pipes', on sait
** par avance que le maillon '*read' existe
*/
