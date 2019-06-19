/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_eval_route.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:40:20 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/19 17:40:24 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Exemple :
**
** $> cat maps/eval_instance.map
** #   / - - - - - B - - - - - - \
** # A - C - D - E - F - - - - - - Z
** # | \ G - H - I - J - - - - - / |
** #  \ K - M - N - O - P - Q - R /
** 13
** ##start
** A 0 0
** B 0 0
** C 0 0
** D 0 0
** E 0 0
** F 0 0
** G 0 0
** H 0 0
** I 0 0
** J 0 0
** K 0 0
** # Pas de salle 'L' - Reserve aux fourmis
** M 0 0
** N 0 0
** O 0 0
** P 0 0
** Q 0 0
** R 0 0
** ##end
** Z 0 0
** A-B
** A-C
** A-G
** A-K
** B-Z
** C-D
** D-E
** E-F
** F-Z
** G-H
** H-I
** I-J
** J-Z
** K-M
** M-N
** N-O
** O-P
** P-Q
** Q-R
** R-Z
** $>
**
** 13 fourmis
** Itineraires :
**               A->B->Z                   (3)
**               A->C->D->E->F->Z          (6)
**               A->G->H->I->J->Z          (6)
**               A->K->M->N->O->P->Q->R->Z (9)
**
**  1: L1-B L2-C L3-G L4-K
**  2: L1-Z L2-D L3-H L4-M L5-B L6-C L7-G L8-K
**  3:      L2-E L3-I L4-N L5-Z L6-D L7-H L8-M L9-B L10-C L11-G L12-K
**  4:      L2-F L3-J L4-O      L6-E L7-I L8-N L9-Z L10-D L11-H L12-M L13-B
**  5:      L2-Z L3-Z L4-P      L6-F L7-J L8-O      L10-E L11-I L12-N L13-Z
**  6:                L4-Q      L6-Z L7-Z L8-P      L10-F L11-J L12-O
**  7:                L4-R                L8-Q      L10-Z L11-Z L12-P
**  8:                L4-Z                L8-R                  L12-Q
**  9:                                    L8-Z                  L12-R
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
**           7 / 3 = 2 reste 1 -> 4 + 3 = 7 fourmis passeront par le 1er chemin
** (7 - 3 = 4) / 2 = 2         -> 1 + 2 = 3 fourmis passeront par le 2e chemin
** (4 - 2 = 2) / 1 = 2         -> 1 + 2 = 3 fourmis passeront par le 3e chemin
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
** On peut vouloir ajouter les lignes suivantes avant le retour de la fonction :
**	ft_putstr("meanwhile : ");
**	ft_putnbr((int)meanwhile);
**	ft_putchar('\n');
*/

size_t	li_eval_meanwhile(t_data *data, size_t index)
{
	size_t	i;
	size_t	longest_path_len;
	size_t	current_path_len;
	size_t	meanwhile;

	*(*(*(data->routes + index) + index) + data->size + 1) = 1;
	longest_path_len = *(*(*(data->routes + index) + index) + data->size);
	meanwhile = 1;
	i = 0;
	while (i < index)
	{
		current_path_len = *(*(*(data->routes + index) + i) + data->size);
		*(*(*(data->routes + index) + i) + data->size + 1) = (longest_path_len
				- current_path_len) + 1;
		meanwhile = meanwhile
			+ *(*(*(data->routes + index) + i) + data->size + 1);
		i++;
	}
	return ((meanwhile <= (size_t)data->ants) ? meanwhile : 0);
}

/*
** On assigne a la variable
** *(*(*(data->routes + A) + B) + data->size + 1)
** Le nombre de fourmis devant passer par l'itineraire B de la combinaison A
**
** Pour calculer le nombre d'etapes,
** on soustrait 2 a la somme de la valeurs du poids (longueur) du plus court
** chemin et de la valeur du nombre de fourmis devant l'emprunter
** car ici et contrairement a l'exemple la salle de depart est consideree
** dans le calcul de du poids du plus court chemin
**
** On peut vouloir ajouter les lignes suivantes avant le retour de la fonction :
**	ft_putnbr((int)index);
**	ft_putchar('\n');
**	ft_putnbr((int)*(*(*(data->routes + index) + 0) + data->size));
**	ft_putchar('\n');
**	ft_putnbr((int)*(*(*(data->routes + index) + 0) + data->size + 1));
**	ft_putchar('\n');
*/

size_t	li_eval_steps(t_data *data, size_t index)
{
	size_t	ret_val;
	size_t	ants;
	size_t	i;

	if (index == 0)
	{
		*(*(*(data->routes + 0) + 0) + data->size + 1) = (size_t)data->ants;
	}
	else if ((ret_val = li_eval_meanwhile(data, index)) == 0)
		return (0);
	else
	{
		ants = (size_t)data->ants - ret_val;
		i = 0;
		while (ants > 0)
		{
			(*(*(*(data->routes + index) + (i % (index + 1)))
				+ data->size + 1))++;
			i++;
			ants--;
		}
	}
	return (*(*(*(data->routes + index) + 0) + data->size)
			+ *(*(*(data->routes + index) + 0) + data->size + 1) - 2);
}

int		li_eval_route(t_data *data, size_t i)
{
	size_t	ret_val;

	if ((ret_val = li_eval_steps(data, i)) > 0)
	{
		if (ret_val < data->best_steps)
		{
			data->best_steps = ret_val;
			data->best_route = i;
		}
		return (1);
	}
	else
	{
		return (0);
	}
}
