/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:02:14 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/30 19:12:40 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Schema de fonctionnement du programme :
** | li_options
**     | ft_options
**         | aux_ft_options
**             | ft_strchr (L)
**     | li_get_output (R)
**         | ft_strlen (L)
**         | li_print_output
** | li_help (O)
**     | ft_putstr (L)
**     | li_usage
**         |ft_putstr (L)
** | li_usage
**     | ft_putstr (L)
** | li_parse_input
**     | li_parse_ants
**         | li_get_next_non_comment_line (*)
**         | li_match_ants
**             | ft_is_int (L)
**         | free (S)
**     | li_parse_rooms
**         | li_allocate_room (*)
**         | li_get_next_non_comment_line (*)
**         | li_match_room
**             | li_deal_sharp_mark
**                 | ft_strcmp (L)
**                 | free (S)
**             | aux_li_match_room
**                 | ft_is_int (L)
**             | li_is_name_available
**                 | ft_strcmp (L)
**             | free (S)
**     | li_allocate_map (*)
**         | aux_li_allocate_map
**     | free (S)
**     | li_parse_pipes
**         | li_get_next_non_comment_line (*)
**         | li_match_pipe
**             | ft_strcmp (L)
**             | li_actualise_map
**         | free (S)
**     | li_shorten_map_pipes (*)
**         | li_fill_bond_summary
** | li_print_output
** | lem_in
**     | li_bhandari
**         | li_bhandari_max_iteration
**         | li_allocate_paths (*)
**         | li_allocate_routes (*)
**             | aux_li_allocate_routes
**         | li_order_rooms
**         | li_initialise_weights
**         | li_bellman_ford
**             | aux_li_bellman_ford
**                 | li_ping_neighboor
**         | li_reverse_path
**         | li_build_route
**             | li_copy_previous_route
**             | li_copy_last_path
**             | li_remove_edges
**                 | li_melt_paths
**                     | li_edge_len
**             | li_order_paths
**         | li_eval_route
**             | li_eval_steps
**                 | li_eval_meanwhile
**             | li_swap_paths
**     | li_move_ants
**         | li_allocate_ant_tab (*)
**             | li_size_ttoa
**                 | li_color_ants (O)
**         | li_steps_length (O)
**         | li_prepare_steps_str (O)
**         | li_ants_distribution
**         | li_display_steps (O)
**         | aux_li_move_ants
**             | li_get_output (R)
**                 | ft_strlen (L)
**                 | li_print_output
**         | li_get_output (R)
**             | ft_strlen (L)
**             | li_print_output
** | li_memory_liberator
** | li_error
** | li_print_output
**
** Note :
** On aurait pu appeler 'li_eval_routes' apres chaque combinaison d'itineraires
** decouverte, afin de s'arreter des lors qu'une combinaison n'exploitait pas
** l'integralite de ses itineraires pour faire circuler les fourmis
** Cependant, cela obligerait a allouer 'max_paths' et non 'path_nb' tableaux
** dans la variable 'routes', car alors on ne saurait pas a l'avance combien
** d'itineraires 'bhandari' identifierait
**
** Rappel :
** Dans 'data->paths'
** - Au terme de 'li_bhandari' :
**   L'element d'index 'data->size' de chaque itineraire correspond l'index de
**   la salle de depart
** Dans 'data->routes'
** - Au terme de 'li_build_routes' :
**   L'element d'index 'data->size' de chaque itineraire correspond a l'index de
**   la salle d'arrivee (la longueur de l'itineraire)
** - Au terme de 'li_eval_routes' :
**   L'element d'index 'data->size + 1' correspond au nombre de fourmis devant
**   emprunter cet itineraire (valeur qui sera decrementee jusqu'a '0' lors
**   de l'appel de 'li_distribute_ants')
**
** Exemple 01 (Absence de point de congestion):
**
** 4 fourmis:
** A->B->C->J
** A->D->E->F->J
** A->G->H->I->J
**
** 1 chemin : 6 tours
** 2 chemins : 6 tours
** 3 chemins : 5 tours
**
** Reflexion :
** S'il est strictement plus rapide de passer par 1 chemin que par 2, alors cela
** signifie que le 2nd chemin n'est pas emprunte, et donc que la recherche d'un
** eventuel 3eme chemin (necessairement de longueure >= au 2eme) est derisoire
** Note :
** Ne pas omettre que la decouverte d'un nouveau chemin, en raison de sa
** superposition potentielle avec les chemins precedemment decouverts, peut
** entrainer une deviation provoquant rallongement de ces derniers !
**
**
** Soit A le nombre de fourmis a devoir traverser
**
** Soit L(n) la longueur du plus long chemin decouvert lors de l'etape n
**
** Soit S(n) le nombre de fourmis total ayant traverse la fourmiliere de part en
** part le temps que la 1ere fourmi ayant emprunte le plus long itineraire
** atteigne la sortie
** Pour n = 1 :
** S(1) = 1
** Pour n > 1 :
** S(n) = S(n - 1) + [(L(n) - L(n - 1)) * (n - 1)] + 1
**
** Pour n > 1, soit D(n) la difference entre S(n) et S(n - 1)
** D(n) = [(L(n) - L(n - 1)) * (n - 1)] + 1
**
** La combinaison de chemin de l'etape 'n' est parfaitement exploite ssi on a :
** (A - S(n)) % n == 0
** ie
** A % n == S(n) % n
**
** Exemple 02 (Absence de point de congestion):
**
**   A % n            S(N) % n
** 5 % 1 = 0    &    1 % 1 = 0
** 5 % 2 = 1    &    3 % 2 = 1
** 5 % 3 = 2    &    4 % 3 = 1
** 5 % 4 = 1    &    5 % 4 = 1
**
** 5 fourmis:
** A->B->Z
** A->C->D->Z
** A->E->F->Z
** A->G->H->Z
**
** 1 chemin : 6 tours
** 2 chemins : 5 tours
** 3 chemins : 5 tours
** 4 chemins : 4 tours
**
** Exemple 3 (Presence de point de congestion):
**
** On cherche un nombre de fourmis > 6 qui soit congru a 0 modulo 3
** et qui ne soit pas congru a 1 modulo 2
** ie
** un multiple de 6 strictement superieur a 6
**
** 12 fourmis:
**
** 0  1  2  3
** A->B->C->D->Z (12)
** 15 etapes
**
** 0  1  2  3  4  5  6  7  8  9  10
** A->B->C->D->E->F->G->H->I->J->Z (7)
** A->B->C->D->E->F->G->H->I->J->K->Z (5)
** 16 etapes
**
** 0  1  2  3  4  5  6  7  8  9  10 11
** A->B->C->D->E->F->G->H->I->J->Z (5)
** A->B->C->D->E->F->G->H->I->J->K->Z (4)
** A->B->C->D->E->F->G->H->I->J->K->M->Z (3)
** 14 etapes
*/

int		lem_in(t_data *data)
{
//	li_epur(data);
	if (!li_bhandari(data))
	{
		return (0);
	}
	else
	{
		return (li_move_ants(data) ? 1 : 0);
	}
}

/*
** 'data.ants' est initialisee dans 'li_match_ants'
** 'data.size' est initialisee dans 'li_parse_rooms'
** 'data.path_nb' est initialisee dans 'li_bhandari'
** 'data.max_paths' est initialisee dans 'li_bhandari_max_iterations'
** 'data.best_steps' est initialisee dans 'li_eval_routes'
** 'data.best_route' est initialisee dans 'li_eval_routes'
*/

void	li_initialise_data(t_data *data)
{
	data->rooms = NULL;
	data->map = NULL;
	data->paths = NULL;
	data->routes = NULL;
	(data->output).index = 0;
	data->ant_tab = NULL;
}

int		main(int argc, char **argv)
{
	t_data	data;
	int		ret_val;

	data.rooms = NULL;
	data.map = NULL;
	data.paths = NULL;
	data.routes = NULL;
	(data.output).index = 0;
	data.ant_tab = NULL;
	if (!(ret_val = (!li_options(&data, argc, argv) || data.help) ? 0 : 1))
		data.help ? li_help() : li_usage();
	else
	{
		ret_val = li_parse_input(&data);
		li_print_output(&data);
		if (!ret_val || !(ret_val = (!data.ants || lem_in(&data)) ? 1 : 0))
			li_error();
	}
	li_memory_liberator(&data);
	if (ret_val)
		li_print_output(&data);
//	li_stats(&data);
	return (0);
}
