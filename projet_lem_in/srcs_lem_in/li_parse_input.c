/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:28:04 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/10 22:44:51 by lcabanes         ###   ########.fr       */
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
	if (((*ret_gnl) = li_get_next_non_comment_line(data, line)) == 1)
	{
		return (li_match_ants(data, *line));
	}
	else
	{
		return (0);
	}
}

/*
** Etant donne que seule la multiplication par '1' laisse une valeur
** a l'identique, et qu'il est necessaire de distinguer les commentaires
** des descriptions de salle afin de savoir quand liberer la memoire,
** on ne peut l'utiliser pour decrire a la fois ces 2 entites dans la variable
** '(t_room *)->role' et par extension dans 'wit'
*/

int		li_parse_rooms(t_data *data, char **line, int *ret_gnl)
{
	t_room	**current;
	int		wit;

	current = &(data->rooms);
	wit = 1;
	while (wit > 0 && !(wit % 5 == 0)
			&& ((*current) || li_allocate_room(current))
			&& ((*ret_gnl) = li_get_next_non_comment_line(data, line)) == 1)
	{
		li_match_room(data, *line, &current, &wit);
	}
	return (wit == 30 ? 1 : 0);
}

/*
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
	return ((*ret_gnl == 0) ? 1 : 0);
}

/*
** Etant donne qu'on appelle 'gel_next_line_backslash_zero'
** en lui passant l'adresse de 'tmp->line',
** il est necessaire de d'allouer un maillon avant
** d'entrer dans la boucle conditionnelle
*/
/*
** Allocation dynamique de memoire dans 'li_get_input'
** (t_input *)*input : data->input (liste chainee)
** (char *)line : (t_input *)->line (dans chaque maillon)
*/

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
