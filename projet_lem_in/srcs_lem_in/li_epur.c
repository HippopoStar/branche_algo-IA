/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_epur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:20:44 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/24 22:48:57 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**      F - G
**     /    |\       .V
**    E     H I
**    |      \|
**    D       J        Q
**     \     /        /
**      C - K    O - P
**     /        /
** A - B - M - N - R - Z
**        / \
**       S - T
**            \      W - X
**             U      \ /
**                     Y
*/
/*
** Etape 1:
** - eliminer les salles isolees [V]
** Etape 2:
** - eliminer recursivement les salles n'ayant qu'une liaison [Q-P-O | U]
**    (si le nombre de liaisons de la salle atteinte '- 1' vaut :
**    '0' : l'eliminer
**    '1' : l'eliminer et poursuivre
**    '+' : s'arreter
** Etape 3:
** - eliminer les boucles
**     Pour chaque salle :
**     - Tant qu'il existe un couple de laisons
**       | OU | Si la salle possede uniquement 2 liaisons
**       ... vers des salles voisines comportant
**           chacune 1 seule autre liaison [G | S | W]
**         - Tant que les salles atteintes par chacun des 2 itineraires
**           ne sont pas confondues (condition necessaire, voir [W-X-Y]),
**           et qu'elles ne possedent qu'une seule autre liaison
**             - Suivre ces liaisons [G->H->J ; G->I->J | S->M ; S->T->M | W[...]]
**         - Si elles rejoignent toutes 2 une meme salle
**           ou qu'elle se sont toutes les 2 rejointes
**             - Eliminer le plus long trajet vers cette meme salle [I | T | W[...]]
**
** Repeter les etapes 2 et 3 autant de fois que necessaire
*/

/*
** Dans la fonction 'li_erase_alone', si une suite de liaisons
** n'est pas reliee au reste de la fourmiliere,
** la derniere salle se verra isolee mais non effacee
** lors de cet appel
**
**			ft_putstr("li_erase_alone\n");
*/

void	li_erase_alone(t_data *data, size_t i)
{
	size_t	tmp;

	if ((*(data->map + i))->nb_of_bonds == 0)
	{
		ft_putstr("li_erase_alone\n");
		li_erase_room(data, i);
	}
	else
	{
		while ((*(data->map + i))->nb_of_bonds == 1 && !(i == 0 || i == data->size - 1))
		{
			tmp = *((*(data->map + i))->bond_sum + 0);
			ft_putstr("li_erase_alone\n");
			li_erase_room(data, i);
			i = tmp;
		}
		if ((*(data->map + i))->nb_of_bonds == 0)
		{
			ft_putstr("li_erase_alone\n");
			li_erase_room(data, i);
		}
	}
}

size_t	li_forward(t_data *data, size_t i, size_t j)
{
	if ((*(data->map + j))->nb_of_bonds == 2 && !(j == 0 || j == data->size - 1))
	{
		if (*((*(data->map + j))->bond_sum + 0) == i)
		{
			return (*((*(data->map + j))->bond_sum + 1));
		}
		else
		{
			return (*((*(data->map + j))->bond_sum + 0));
		}
	}
	else
	{
		return (j);
	}
}

void	li_epur(t_data *data)
{
	size_t	i;

	data->eff = data->size - 1;
	data->wit = 1;
	while (data->wit > 0)
	{
		data->wit = 0;
		i = 1;
		while (i < data->eff)
		{
			if ((*(data->map + i))->nb_of_bonds < 2)
			{
				li_erase_alone(data, i);
			}
			else
			{
				li_erase_cycle(data, i);
			}
			i++;
		}
	}
/*
	ft_putstr("Dans 'li_epur' :\n");
	li_print_map(data);
	i = 0;
	while (i <= data->eff)
	{
		li_display_room_info(data, i);
		i++;
	}
*/
	li_swap_rooms(data, data->size - 1, data->eff);
	data->size = data->eff + 1;
/*
	i = 0;
	while (i < data->size)
	{
		li_display_room_info(data, i);
		i++;
	}
*/
}
