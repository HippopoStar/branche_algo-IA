/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_shorten_map_pipes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:40:14 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/19 20:58:47 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Ce fichier permet de faire passer la complexite du programme de :
** O(nb_de_salles ^ 3 * nb_max_de_chemins_simultanes)
** -> Bellman-Ford : O(nb_de_salles ^ 3)
** -> Bhandari : O(nb_max_de_chemin_simultanes)
** a :
** O(nb_de_salles * nb_total_de_liaisons * nb_max_de_chemins_simutanes)
** -> Bellman-Ford : O(nb_de_salles ^ 2 * nb_moyen_de_liaisons_par_salle)
**                 = O(nb_de_salles ^ 2 * (nb_total_de_liaisons / nb_de_salles))
**                 = O(nb_de_salles * nb_total_de_laisons)
** -> Bhandari : O(nb_max_de_chemins_simultanes)
*/
/*
** Nul besoin d'ajouter la condition '&& j < data->size' dans structure
** de controle de la boucle conditionnelle de la fonction 'li_fill_bond_summary'
** car la 1ere conditions est supposee etre suffisante
**
** On peut vouloir ajouter disseminees de part et d'autre
** dans 'li_fill_bond_summary' les lignes suivantes :
**	ft_putstr(current->name); //______________________ TODO
**	ft_putstr(": "); //_______________________________ TODO
**		ft_putstr((*(current->bond_sum + i))->name); //TODO
**		ft_putchar(' '); //___________________________ TODO
**	ft_putchar('\n'); //______________________________ TODO
*/

void	li_fill_bond_summary(t_data *data, t_room *current)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < current->nb_of_bonds)
	{
		while (*(current->pipes + j) == 0)
		{
			j++;
		}
		*(current->bond_sum + i) = *(data->map + j);
		i++;
		j++;
	}
}

/*
** On alloue '4 * data->bonds * sizeof(int)'
** car chaque liaison est repertoriee 2 fois (une dans chaque sens)
** et contient 2 informations sous la forme d'un 'int'
** (d'une part l'index de la salle correspondante et d'autre part son poids)
**
** On peut vouloir ajouter la ligne suivante a la fin de 'li_shorten_map_pipes':
**	ft_putstr((*((*(data->map + ?))->bond_sum + ?))->name);
*/
/*
** Allocation dynamique de memoire dans 'li_shorten_map_pipes'
** (t_room **)(*(data->map + 0))->bond_sum
*/

int		li_shorten_map_pipes(t_data *data)
{
	size_t	i;
	size_t	j;

	if (!((*(data->map + 0))->bond_sum = (t_room **)malloc(2 * data->bonds
					* sizeof(t_room *))))
		return (0);
	i = 0;
	j = 0;
	while (i < data->size)
	{
		(*(data->map + i))->bond_sum = &(*((*(data->map + 0))->bond_sum + j));
		li_fill_bond_summary(data, *(data->map + i));
		j = j + (*(data->map + i))->nb_of_bonds;
		i++;
	}
	return (1);
}
