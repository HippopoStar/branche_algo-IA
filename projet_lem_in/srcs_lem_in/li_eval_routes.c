/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_eval_routes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:24:09 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/28 16:24:38 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Exemple :
** 13 fourmis
** Itineraires :
**               A->B->Z                   (3)
**               A->C->D->E->F->Z          (6)
**               A->G->H->I->J->Z          (6)
**               A->K->L->M->N->O->P->Q->Z (9)
**
**  1: L1-B L2-C L3-G L4-K
**  2: L1-Z L2-D L3-H L4-L L5-B L6-C L7-G L8-K
**  3:      L2-E L3-I L4-M L5-Z L6-D L7-H L8-L L9-B L10-C L11-G L12-K
**  4:      L2-F L3-J L4-N      L6-E L7-I L8-M L9-Z L10-D L11-H L12-L L13-B
**  5:      L2-Z L3-Z L4-O      L6-F L7-J L8-N      L10-E L11-I L12-M L13-Z
**  6:                L4-P      L6-Z L7-Z L8-O      L10-F L11-J L12-N
**  7:                L4-Q                L8-P      L10-Z L11-Z L12-O
**  8:                L4-Z                L8-Q                  L12-P
**  9:                                    L8-Z                  L12-Q
** 10:                                                          L12-Z
**
**   1 par 8
** + 4 par 5    + 1 par 5
** + 4 par 5    + 1 par 5
** + 7 par 2    + 4 par 2
** = 16 > 13    = 6 <= 13
**              -> La combinaison de chemins la plus opti'
**              -> 3 chemins
**              -> steps_to_add = (nb de fournmis
**                                 - nb de fourmis pouvant traverser
**                                   pendant que la fourmi empruntant
**                                   le chemin le plus long traverse la
**                                   fourmiliere)
**                                / nb de chemins
**                              = (13 - 6) / 3
**                              = 7 / 3
**                              = 2 (euclidienne : reste 1)
**                              -> prendre la partie superieure
**                              -> a = (b % c == 0) ? b / c : (b / c) + 1;
**
** Nombre total d'etapes :
** longueur du chemin le plus long a emprunter + steps_to_add = 5 + 3
**                                                            = 8
**
** 13 - 6 = 7 est le nombre de fourmis devant encore entrer dans la fourmiliere
** apres que la premiere fourmis ayant emprunte le chemin le plus long
** soit arrive
** (nb de fourmis restantes / nb de chemin restants) = nb de fourmis a envoyer
**                                                     dans le chemin courant
**           7 / 3 = 2 reste 1 -> 4 + 3 = 7 fourmis passeront par le plus court chemin
** (7 - 3 = 4) / 2 = 2         -> 1 + 2 = 3 fourmis passeront par le 2e plus court chemin
** (4 - 2 = 2) / 1 = 2         -> 1 + 2 = 3 fourmis passeront par le 3e plus court chemin
**
**  1: L1-B L2-C L3-G
**  2: L1-Z L2-D L3-H L4-B L5-C L6-G
**  3:      L2-E L3-I L4-Z L5-D L6-H L7-B L8-C L9-G
**  4:      L2-F L3-J      L5-E L6-I L7-Z L8-D L9-H L10-B
**  5:      L2-Z L3-Z      L5-F L6-J      L8-E L9-I L10-Z L11-B
**  6:                     L5-Z L6-Z      L8-F L9-J       L11-Z L12-B
**  7:                                    L8-Z L9-Z             L12-Z L13-B
**  8:                                                                L13-Z
**  9:
** 10:
**
*/

size_t	li_eval_meanwhile(t_data *data, size_t index)
{
	size_t	i;
	size_t	longest_path_length;
	size_t	current_path_length;
	size_t	meanwhile;

	longest_path_length = *(*(*(data->routes + index) + index) + data->size);
	meanwhile = 1;
	i = 0;
	while (i < index)
	{
		current_path_length = *(*(*(data->routes + index) + i) + data->size);
		*(*(*(data->routes + index) + i) + data->size + 1)
			= (longest_path_length - current_path_length) + 1;
		meanwhile = meanwhile + (longest_path_length - current_path_length) + 1;
		i++;
	}
	return ((meanwhile <= data->size) ? meanwhile : 0);
}

size_t	li_eval_steps(t_data *data, size_t index)
{
	size_t	ret_val;
	size_t	ants;
	size_t	i;

	if (index == 0)
	{
		*(*(*(data->routes + 0) + 0) + data->size + 1) = data->size;
	}
	else if ((ret_val = li_eval_meanwhile(data, index)) == 0)
	{
		return (0);
	}
	else
	{
		ants = data->size - ret_val;
		i = 0;
		while (ants > 0)
		{
			(*(*(*(data->routes + index) + (i % index)) + data->size + 1))++;
			ants--;
		}
	}
	return (*(*(*(data->routes + index) + 0) + data->size)
			+ *(*(*(data->routes + index) + 0) + data->size + 1) - 1);
}

size_t	li_eval_routes(t_data *data)
{
	size_t	ret_val;
	size_t	best_value;
	size_t	best_index;
	size_t	i;

	best_value = li_eval_steps(data, 0);
	best_index = 0;
	i = 1;
	while (i < data->path_nb && (ret_val = li_eval_steps(data, i)) > 0)
	{
		if (ret_val < best_value)
		{
			best_value = ret_val;
			best_index = i;
		}
		i++;
	}
	data->best_steps = best_value;
	data->best_route = best_index;
	return (best_index);
}
