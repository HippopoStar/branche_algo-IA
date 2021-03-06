/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_bellman_ford.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:33:06 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/19 21:15:26 by lcabanes         ###   ########.fr       */
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
** On peut vouloir ajouter les lignes suivantes au debut de 'li_ping_neighbour':
** (11 lignes)
**	ft_putstr("i : ");
**	ft_putnbr((int)i);
**	ft_putstr("\nj : ");
**	ft_putnbr((int)j);
**	ft_putstr("\ntarget id : ");
**	ft_putnbr((int)target_id);
**	ft_putstr("\n(*(data->map + i))->name : ");
**	ft_putstr((*(data->map + i))->name);
**	ft_putstr("\n(*((*(data->map + i))->bond_sum + j))->name : ");
**	ft_putstr((*((*(data->map + i))->bond_sum + j))->name);
**	ft_putchar('\n');
*/

void	li_ping_neighbour(t_data *data, size_t i, size_t j, size_t target_id)
{
	int		wei;

	if (!(*((*(data->map + i))->pipes + target_id) == 0)
			&& ((wei = (*(data->map + i))->weight
					+ (int)(*((*(data->map + i))->pipes + target_id)))
				< (*((*(data->map + i))->bond_sum + j))->weight))
	{
		(*((*(data->map + i))->bond_sum + j))->ancestor = i;
		(*((*(data->map + i))->bond_sum + j))->weight = wei;
		(*((*(data->map + i))->bond_sum + j))->except = *((*(data->map
						+ i))->pipes + target_id) == (signed char)1 ? 0 : 1;
	}
}

void	aux_li_bellman_ford(t_data *data, size_t i)
{
	size_t	j;
	size_t	target_id;

	j = 0;
	if (!((*(data->map + i))->allowed || (*(data->map + i))->except))
	{
		while (j < (*(data->map + i))->nb_of_bonds)
		{
			target_id = (*((*(data->map + i))->bond_sum + j))->id;
			if (*((*(data->map + i))->pipes + target_id) == (signed char)(-1))
			{
				li_ping_neighbour(data, i, j, target_id);
			}
			j++;
		}
	}
	else
	{
		while (j < (*(data->map + i))->nb_of_bonds)
		{
			target_id = (*((*(data->map + i))->bond_sum + j))->id;
			li_ping_neighbour(data, i, j, target_id);
			j++;
		}
	}
}

/*
** On ne peut avoir 'data->size == 0'
** (car alors 'li_parse_rooms' renverrait une erreur)
**
** Si le poids d'une salle vaut 'data->size',
** c'est qu'elle n'a pas encore ete atteinte depuis l'appel
** de 'li_initialise_weights'
*/

void	li_bellman_ford(t_data *data)
{
	size_t	iteration;
	size_t	i;

	iteration = 0;
	while (iteration < data->size)
	{
		aux_li_bellman_ford(data, 0);
		i = 1;
		while (i < data->size)
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
