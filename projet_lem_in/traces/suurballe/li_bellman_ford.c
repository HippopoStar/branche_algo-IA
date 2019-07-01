/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_bellman_ford.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:33:06 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/30 18:07:38 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Si on a atteint la salle suivante
** (en lui ayant decouvert un nouveau poids minimum)
** en passant par une liaison de poids positif,
** on place la valeur de sa variable 'except' sur '0',
** en revanche si on l'a atteinte en passant par une liaison de poids negatif,
** on place la valeur de sa variable 'except' sur '1'
**
** (Notez qu'on ne peut atteindre de salle en passant par une liaison
** de poids nul)
**
** Une salle ne peut posseder plus de 1 liaison de poids negatif, car :
** - Dans une salle possedant une liaison de poids negatif :
**     - emprunter une liaison de poids negatif dans un nouvel itineraire
**       la detruit
**     - emprunter une liaison de poids positif alors qu'on possede par ailleurs
**       une liaison de poids negatif, detruit cette liaison
**       (la liaison de poids negatif resultante sera dans la salle atteinte)
** - Dans une salle ne possedant pas de liaison de poids negatif :
**     - atteindre une salle possedant une liaison de poids negatif
**       pre-existante force cette derniere a l'emprunter, la detruisant ainsi
**
** Tel quel, Bellman-Ford ne preserve pas de l'apparition de cycles de poids
** strictement negatif,
** et ajouter une condition '&& !((*(data->map + target))->ancestor == i)'
** fait perdre l'assurance de decouvrir l'itineraire le plus court
**
** La condition '&& !(i == target)' on a deja l'assurance que ce n'est pas le
** cas grace a 'li_match_pipe'
**
** La condition '!(*((*(data->map + i))->pipes + target) == 0)', quant a elle,
** est necessaire, car elle permet de s'assurer que la liaison n'a pas ete
** fermee a la suite de la decouverte anterieure d'un itineraire
**
** Remarque :
** Etant donne le fait que Bhandari s'assure d'avoir trouver la combinaison de
** chemin la plus courte a chaque etape, le poids de la salle de depart ne peut
** descendre en dessous de '0' apres avoir ete atteint par une suite de liaison
** de poids strictement negatifs, car pour arriver au depart de cette suite de
** liaisons, il aura fallut emprunter un itineraire de poids superieur a la
** valeur absolue de cet suite liaison
**
** (8 lignes)
**				if (!(ft_strcmp((*(data->map + i))->name, "Bzd2")
					  || ft_strcmp((*(data->map + target))->name, "O_z2")))
**				{
**					ft_putstr("\033[33maux_li_bellman_ford\033[00m\n");
**					li_display_room_info(data, (*(data->map + i))->ancestor);
**					li_display_room_info(data, i);
**					li_display_room_info(data, target);
**				}
*/

/*
** void	li_suurballe(t_data *data, size_t i, size_t target);
*/

void	li_suurballe(t_data *data, size_t i, size_t target)
{
	int		tmp_wit;
	size_t	tmp_wei;
	size_t	forced;
	size_t	j;

	tmp_wei = (*(data->map + target))->weight;
	(*(data->map + target))->weight = (*(data->map + i))->weight + 1;
	j = 0;
	while (j < (*(data->map + target))->nb_of_bonds)
	{
		forced = *((*(data->map + target))->bond_sum + j);
		if (*((*(data->map + target))->pipes + forced) == (signed char)(-1))
		{
			tmp_wit = data->wit;
			data->wit = 0;
			li_ping_neighbour(data, target, forced);
			if (data->wit == 1)
			{
				(*(data->map + target))->ancestor = i; //Hmmm...
			}
			data->wit = (tmp_wit || data->wit) ? 1 : 0;
		}
		j++;
	}
	(*(data->map + target))->weight = tmp_wei;
}

/*
** L'appel de 'li_ping_neighbour' dans 'li_tunnel_back'
** ne va pas changer la valeur de 'target_2->ancestor'
** car a present 'li_ping_neighbour' n'impact que les
** salles atteintes grace a une liaison de poids '1'
**
** Nul besoin de stocker le poids initial de 'target'
**
** Cependant, il est important que '(*(data->map + 0))->ancestor == 0'
**
** 'i'->'target' : wei++;
** 'target'->'ancestor' : wei--;
**	wei = (*(data->map + i))->weight;
**
** La fonction 'li_tunnel_back' necessite de ne pas remettre les
** variables '(t_room *)->ancestor' a 'data->size' pour les
** salles dont la variable 'allowed' est a '0',
** dans le corps de la fonction 'li_initialise_weights'
** De meme pour les variables '(t_room *)->weights' !
**
** Par ailleurs, pour le bon fonctionnement de 'li_tunnel_back',
** il ne faut pas changer les variables '(t_room *)->ancestor' des salles
** intervenants dans un chemin prealable, et par consequent ne pas appeler
** 'li_ping_neighbour' dans le cas ou on atteint une salle dont la
** variable '(t_room *)->allowed' est a '0'
*/

/*
** void	li_tunnel_back(t_data *data, size_t i, size_t target);
*/

/*
** Il n'est pas cense etre possible de passer le poids de la salle de depart
** en negatif, car cela impliquerait qu'on ait fait plus de trajet en remontant
** un ancien chemin, que de trajet pour rejoindre la salle de depart de ce
** roll-back, or cela impliquerait que s'ait ete par ce 2nd trajet en question
** qu'il eut fallu passer lors de la decouvert du 1er afin d'obtenir
** l'itineraire le plus court
*/

void	li_ping_neighbour(t_data *data, size_t i, size_t target)
{
	int		wei;

	if (!(*((*(data->map + i))->pipes + target) == 0)
			&& ((wei = (*(data->map + i))->weight
					+ (int)(*((*(data->map + i))->pipes + target)))
				< (*(data->map + target))->weight))
	{
		if ((*(data->map + target))->allowed == 0 && (*(data->map + i))->allowed == 1 && !(i == data->size - 1 || target == 0))
		{
			li_suurballe(data, i, target);
		}
//		if ((*(data->map + i))->allowed == 0 || (*(data->map + target))->allowed == 1)
		else
		{
			(*(data->map + target))->ancestor = i;
			(*(data->map + target))->weight = wei;
			data->wit = 1;
		}
	}
}

/*
** Au vu de la condition d'appel de 'li_ping_neighbour',
** il est important que la variable
** '(*(data->map + data->size - 1))->allowed' ne soit pas
** mise a '0' dans 'li_reverse_path'
*/

void	aux_li_bellman_ford(t_data *data, size_t i)
{
	size_t	j;
	size_t	target;

	j = 0;
	while (j < (*(data->map + i))->nb_of_bonds)
	{
		target = *((*(data->map + i))->bond_sum + j);
		if (!(ft_strcmp((*(data->map + i))->name, "Bzd2") || ft_strcmp((*(data->map + target))->name, "O_z2")))
		{
			ft_putstr("\033[33maux_li_bellman_ford\033[00m\n");
			li_display_room_info(data, (*(data->map + i))->ancestor);
			li_display_room_info(data, i);
			li_display_room_info(data, target);
		}
		li_ping_neighbour(data, i, target);
		j++;
	}
}

/*
** On ne peut avoir 'data->size == 0'
** (car alors 'li_parse_rooms' renverrait une erreur)
**
** Si le poids d'une salle vaut 'data->size',
** c'est qu'elle n'a pas encore ete atteinte depuis l'appel
** de 'li_initialise_weights'
**
** Avec l'arrivee de 'li_suurballe', la condition
** 'if (!((*(data->map + i))->weight == (int)data->size))'
** est a mediter
**
** L'appel initial 'aux_li_bellman_ford(data, 0)'
** est place avant la boucle car il est pertinent de
** le lancer une seule fois, etant donne que le poids de la
** salle de depart ne va pas etre amene a changer,
** et il permet d'initialiser la variable 'data->wit' a '1'
*/

void	li_bellman_ford(t_data *data)
{
	size_t	iteration;
	size_t	i;

	aux_li_bellman_ford(data, 0);
	iteration = 0;
	while (iteration < data->size && data->wit == 1)
	{
		data->wit = 0;
		i = 1;
		while (i < data->size - 1)
		{
			if (!((*(data->map + i))->weight == (int)data->size))
			{
				aux_li_bellman_ford(data, i);
			}
			i++;
		}
		iteration++;
	}
}
