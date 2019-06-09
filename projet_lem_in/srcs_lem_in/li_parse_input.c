/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:28:04 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/09 20:48:12 by lcabanes         ###   ########.fr       */
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
	while (((*ret_gnl) = get_next_line_backslash_zero(0, line)) == 1
			&& (ret_val = li_match_ants(*line, data)) == 0)
	{
		li_get_output(data, *line);
		free(*line);
	}
	if (*line)
	{
		li_get_output(data, *line);
		free(*line);
	}
	return (ret_val);
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
	int		ret_val;
	t_room	**tmp;
	int		wit;

	*tmp = data->rooms;
	wit = 1;
	ret_val = 0;
	while (ret_val >= 0 && wit % 5 != 0
			&& ((*tmp) || li_allocate_room(tmp))
			&& ((*ret_gnl) = get_next_line_backslash_zero(0, line)) == 1)
	{
		li_get_output(data, *line);
		ret_val = li_match_rooms(*line, data);
		if (!(ret_val == 1 || ret_val == 5))
		{
			free(*line);
		}
		wit = wit * (*tmp)->role;
		if (ret_val == 1)
		{
			*tmp = (*tmp)->next;
		}
	}
	return (wit == 30 && ret_val >= 0 ? 1 : 0);
}

/*
** Ne pas oublier que des commentaires peuvent suivre la fin
** de la declaration de la fourmiliere
*/

int		li_parse_pipes(t_data *data, char **line, int *ret_gnl)
{
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

int		li_get_input(t_data *data, t_input **input)
{
	int		ret_gnl;
	t_input	*tmp;

	if (!((*input) = (t_input *)malloc(sizeof(t_input))))
		return (0);
	tmp = *input;
	while ((ret_gnl = get_next_line_backslash_zero(0, &(tmp->line))) == 1)
	{
		li_get_output(data, tmp->line);
		li_get_output(data, "\n");
		if (!(tmp->next = (t_input *)malloc(sizeof(t_input))))
			return (0);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	li_get_output(data, "\n");
	return ((ret_gnl == 0) ? 1 : 0);
}
