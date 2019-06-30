/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_bhandari.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:33:13 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/19 18:37:08 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	li_bhandari_max_iterations(t_data *data)
{
	int		beg;
	int		end;

	beg = (*(data->map + 0))->nb_of_bonds;
	end = (*(data->map + data->size - 1))->nb_of_bonds;
	if (data->ants < beg && data->ants < end)
	{
		data->max_paths = (size_t)data->ants;
	}
	else
	{
		data->max_paths = (size_t)(beg < end ? beg : end);
	}
}

/*
** On (re)met '(*(data->map + i))->except' a '0' a ce moment-la
*/

void	li_initialise_weights(t_data *data)
{
	size_t	i;

	(*(data->map + 0))->ancestor = 0;
	(*(data->map + 0))->weight = 0;
	i = 1;
	while (i < data->size)
	{
		(*(data->map + i))->ancestor = data->size;
		(*(data->map + i))->weight = (int)data->size;
		(*(data->map + i))->except = 0;
		i++;
	}
}

/*
** On met '(*(data->map + i))->allowed' a '0' a ce moment-la
**
** Cela n'a pas d'impact de mettre la variable
** '(*(data->map + data->size - 1))->allowed' a '0' car cette salle
** n'est pas 'parcourue' a proprement parler lors de l'execution de
** Bellman-Ford
**
** On s'assure s'arreter lorsqu'on est malheureusement tombe sur un cycle de
** poids strictement negatif grace a la condition sur 'pos',
** en revanche cela peut entraver la decouverte de nouveau chemins
**
** On ne rempli pas le champ '*(*(data->paths + data->path_nb) + 0)',
** qui est par defaut a '0'
** (d'ou la validite de la condition 'pos > 0' dans la structure de controle
** de la boucle conditionnelle)
**
** On peut souhaiter ajouter les 2 lignes suivantes au debut de la
** boucle conditionnelle :
**		ft_putstr((*(data->map + j))->name);
**		ft_putstr("<-");
** ainsi qu'a la suite de cette derniere :
**		ft_putstr((*(data->map + i))->name);
**		ft_putchar('\n');
**
** (9 lignes)
**		if (!ft_strcmp((*(data->map + i))->name, "Bzd2"))
**		{
**			ft_putstr("\033[32mli_reverse_path\033[00m\n");
**			ft_putstr("Ancestor :\n");
**			li_display_room_info(data, (*(data->map + i))->ancestor);
**			li_display_room_info(data, i);
**			ft_putstr("Followed by :\n");
**			li_display_room_info(data, j);
**		}
*/
/*
** La fonction 'li_inversed_ancestor' est basee sur la confiance
** concernant le fait qu'il existe bel et bien un tel ancetre,
** car dans le cas contraire elle part dans les choux :
**
** Il est possible qu'un ancien itineraire inverse soit coupe
** a l'occasion de sa fusion avec un autre itineraire,
** il existerait alors une salle de jonction remplissant le 1er
** de 2 criteres mais pas le 2nd, mais dans ce cas,
** suivant l'implementation de 'li_tunnel_front' qui appelle
** 'li_inversed_ancestor', une telle salle ne devrait pas etre appelee,
** car la salle appartenant a l'itineraire recherche devrait avoir
** ete trouvee anterieurement
**
** Fonctionnement :
** On remonte dans le chemin inverse, puis :
** Tant qu'on n'a pas trouve la salle entrante dans le chemin inverse :
**     - On remonte dans le chemin inverse
*/

/*
** void	li_tunnel_front(t_data *data, size_t *i, size_t *pos, int wei);
*/

/*
** Dans cette fonction,
** on pourrait faire usage des '(t_room *)->ancestor'
** que la fonction 'li_tunnel_back' ne modifie pas,
** a condition de ne pas le reset dans 'li_initialise_weights'
** dans le cas des salles ayant leur variable 'allowed' a '0'
*/

/*
** size_t	li_inversed_ancestor(t_data *data, size_t j);
*/

/*
**		i = (!((*(data->map + j))->allowed == 0 && (*(data->map + (*(data->map + j))->ancestor))->allowed == 1)) ? (*(data->map + j))->ancestor : li_inversed_ancestor(data, j);
**
** Avec l'arrivee de 'li_suurballe', ca a a present une importance
** de ne pas mettre la variable '(*(data->map + data->size - 1))->allowed' a '0'
**
** La condition '&& pos > 0' repose sur le fait que l'allocation
** du tableau 'data->paths' se fasse soit accompagnee d'une
** mise des valeurs a '0',
** et sert a prevenir certaines erreurs de boucles infinies
** (idealement, il faudrait pouvoir l'enlever)
**
** Par ailleurs, la variable 'pos' a pour utilite initiale d'eviter d'avoir
** a ecrire '*(*(data->paths + path_nb) + data->size)' un peu partout
**
** Il est necessaire de ne pas mettre la variable
** '(*(data->map + data->size - 1))->allowed' a '0',
** d'ou le 'j = i' avant l'entree dans la boucle conditionnelle, cependant,
** il est egalement necessaire que
** '*(*(data->paths + path_nb) + data->size - 1) == data->size - 1'
**
** 2 solutions :
** - Soit enlever le 'j = i' precedant l'entree dans la boucle conditionnelle,
**   en se servant alors d'un ternaire lors de l'assignation de
**   '(*(data->map + i))->allowed'
** - Soit l'assigner a l'allocation, car c'est une constante dans chaque
**   ligne du tableau
**
** Sachant que la salle d'arrivee ne peut etre jointe en passant
** par une liaison de poids '-1', on sait que le premier 'i', assigne
** avant la boucle, est l'index d'une salle dont la variable 'allowed' vaut '1'
**
** A linstant 'T', je pense egalement qu'il n'est pas possible
** qu'une salle ayant etee atteinte a travers une liaison inverse puisse
** avoisiner la salle de sortie
*/

int		li_reverse_path(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	pos;

	j = data->size - 1;
	if ((i = (*(data->map + j))->ancestor) == data->size)
	{
		return (0);
	}
	pos = data->size - 2;
	j = i;
	while (j > 0 && pos > 0)
	{
		i = (*(data->map + j))->ancestor;
		(*(data->map + j))->allowed = 0;
		*((*(data->map + j))->pipes + i) = (signed char)
			(-(*((*(data->map + i))->pipes + j)));
		*((*(data->map + i))->pipes + j) = (signed char)0;
		*(*(data->paths + data->path_nb) + pos) = j;
		pos--;
		j = i;
	}
	*(*(data->paths + data->path_nb) + data->size) = pos;
	return (j == 0 ? 1 : 0);
}

/*
** Allocation dynamique de memoire dans 'li_allocate_paths'
** (size_t **)data->paths
** (size_t *)*(data->paths + 0)
*/

int		li_allocate_paths(t_data *data)
{
	size_t	i;
	size_t	j;

	if (!(data->paths = (size_t **)malloc(data->max_paths * sizeof(size_t *))))
		return (0);
	if (!(*(data->paths + 0) = (size_t *)malloc(data->max_paths
					* (data->size + 1) * sizeof(size_t))))
		return (0);
	i = 0;
	while (i < data->max_paths)
	{
		*(data->paths + i) = &(*(*(data->paths + 0) + (i * (data->size + 1))));
		j = 0;
		while (j < data->size)
		{
			*(*(data->paths + i) + j) = 0;
			j++;
		}
		*(*(data->paths + i) + data->size - 1) = data->size - 1;
		*(*(data->paths + i) + data->size) = data->size;
		i++;
	}
	return (1);
}

/*
** Ne pas omettre que 'data->ants' == '0' => 'data->max_paths' == '0'
** On fait le choix de ne pas considerer '0' fourmis comme une erreur
**
** Si le nombre de fourmis s'avere valoir '0', 'li_bhandari'
** n'est pas appelee
**
** On pourrait eventuellement trier les salles suivant leur poids appelant une
** fonction dont ce serait le propos apres le 1er passage de Bellman-Ford
** Peut-etre cela eviterait-il de generer des cycles de poids strictement
** negatifs dans la majorite des cas ?
**
** Etant donne que la valeur de retour de 'li_eval_routes' est soit 1 soit 0,
** on peut additionner 'data->path_nb' avec cette valeur de retour plutot
** que de creer une boucle conditionnelle dans laquelle
** incrementer 'data->path_nb'
**
** Un appel de 'li_order_rooms' au moment la 2nd iteration de la boucle
** conditionnelle compromet la correspondance entre les positions des salles
** dans '(t_data *)->map' et leurs positions respectives dans le graphe
** des liaisons '(t_room *)->pipes'
*/

int		li_bhandari(t_data *data)
{
	int		ret_val;

	data->path_nb = 0;
	data->best_steps = (size_t)data->ants * data->size;
	data->best_route = 0;
	li_bhandari_max_iterations(data);
	if (data->max_paths == 0 || !li_allocate_paths(data)
			|| !li_allocate_routes(data))
		return (data->ants == 0 ? 1 : 0);
	ret_val = 1;
	while (data->path_nb < data->max_paths && ret_val == 1)
	{
//		if (data->path_nb == 1)
//			li_order_rooms(data);
		li_initialise_weights(data);
		ft_putstr("Appel de 'li_bellman_ford'\n");
		li_bellman_ford(data);
		ft_putstr("Sortie de 'li_bellman_ford'\n");
		if ((ret_val = li_reverse_path(data))
				&& (ret_val = li_build_route(data, data->path_nb)))
		{
			li_build_route(data, data->path_nb);
			data->path_nb = data->path_nb
				+ ((ret_val = li_eval_route(data, data->path_nb)));
		}
	}
	return (data->path_nb > 0 ? 1 : 0);
}
