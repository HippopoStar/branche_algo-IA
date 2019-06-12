/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:28:04 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/12 18:25:56 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** La fonction 'li_parse_ants' va sauter les commentaires
** qu'elle rencontre jusqu'a recuperer la valeur de 'data->ants'
**
** Notons au passage que si lors d'un de ses appels 'GNL' renvoie '-1' ou '0',
** mecaniquement la fonction renverra '0' en ayant 'free' au prealable
** si necessaire
*/

int		li_parse_ants(t_data *data, char **line, int *ret_gnl)
{
	int		ret_val;

	ret_val = 0;
	if (((*ret_gnl) = li_get_next_non_comment_line(data, line)) == 1)
	{
		ret_val = li_match_ants(data, *line);
		free(*line);
	}
	return (ret_val);
}

int		li_parse_rooms(t_data *data, char **line, int *ret_gnl)
{
	t_room	**current;
	int		wit;

	data->size = 0;
	current = &(data->rooms);
	wit = 1;
	while (wit > 0 && !(wit % 5 == 0)
			&& ((*current) || li_allocate_room(current))
			&& ((*ret_gnl) = li_get_next_non_comment_line(data, line)) == 1)
	{
		li_match_room(data, *line, &current, &wit);
	}
	if (wit % 5 == 0 && !(wit == 30))
	{
		free(*line);
	}
	return (wit == 30 ? 1 : 0);
}

/*
** Etant donne le comportement et les conditions de validite de
** 'li_parse_rooms' dont l'appel precede celui de 'li_parse_pipes', on sait
** par avance que la chaine de caractere '*line' existe
**
** Car dans le cas contraire la condition 'wit % 5 == 0' n'est jamais remplie :
** Par exemple, dans le cas ou aucune declaration de liaison ne suit la fin
** de la declaration des salles, qu'elle est directement suivie par la
** fin de l'entree :
** L'arret de la boucle se fait alors d'apres la variable '(*ret_gnl)'
**
** Ne pas oublier que des commentaires peuvent suivre la fin
** de la declaration de la fourmiliere
*/

int		li_parse_pipes(t_data *data, char **line, int *ret_gnl)
{
	data->bonds = 0;
	while (((*line)
				|| ((*ret_gnl) = li_get_next_non_comment_line(data, line)) == 1)
			&& li_match_pipe(data, *line))
	{
		free(*line);
		*line = NULL;
		(data->bonds)++;
	}
	if ((*ret_gnl) == 1)
	{
		free(*line);
		return (0);
	}
	else
	{
		return (1);
	}
}

int		li_parse_input(t_data *data)
{
	char	*line;
	int		ret_gnl;

	if (li_parse_ants(data, &line, &ret_gnl)
			&& li_parse_rooms(data, &line, &ret_gnl))
	{
		if (!li_allocate_map(data))
		{
			free(line);
			return (0);
		}
		else
		{
			return ((li_parse_pipes(data, &line, &ret_gnl)
						&& li_shorten_map_pipes(data)) ? 1 : 0);
		}
	}
	else
	{
		return (0);
	}
}
