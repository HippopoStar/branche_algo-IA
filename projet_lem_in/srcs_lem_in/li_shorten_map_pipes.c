/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_shorten_map_pipes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:40:14 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/05 21:04:34 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Nul besoin d'ajouter la condition '&& j < data->size' dans structure
** de controle de la boucle conditionnelle de la fonction 'li_fill_bond_summary'
** car la 1ere conditions est supposee etre suffisante
*/

void	li_fill_bond_summary(t_room *current)
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
		*(current->bond_sum + i) = j;
		i++;
		j++;
	}
}

/*
** On alloue '4 * data->bonds * sizeof(int)'
** car chaque liaison est repertoriee 2 fois (une dans chaque sens)
** et contient 2 informations sous la forme d'un 'int'
** (d'une part l'index de la salle correspondante et d'autre part son poids)
*/

int		li_shorten_map_pipes(t_data *data)
{
	size_t	i;
	size_t	j;

	if (!((*(data->map + 0))->bond_sum = (size_t *)malloc(2 * data->bonds * sizeof(size_t))))
		return (0);
	i = 0;
	j = 0;
	while (i < data->size)
	{
		(*(data->map + i))->bond_sum = &(*((*(data->map + 0))->bond_sum + j));
		li_fill_bond_summary(*(data->map + i));
		j = j + (*(data->map + i))->nb_of_bonds;
		i++;
	}
	return (1);
}
