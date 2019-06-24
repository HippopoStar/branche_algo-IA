/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_swap_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:43:53 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/24 22:49:47 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	li_swap_map(t_data *data, size_t pos_a, size_t pos_b)
{
	t_room	*tmp;

	tmp = *(data->map + pos_a);
	*(data->map + pos_a) = *(data->map + pos_b);
	*(data->map + pos_b) = tmp;
}

/*
**	ft_putstr("Appel de \"\033[33mli_swap_bonds\033[00m\"\n");
**	ft_putstr((*(data->map + pos_a))->name);
**	ft_putstr(" | ");
**	ft_putstr((*(data->map + pos_b))->name);
**	ft_putchar('\n');
**	li_display_room_info(data, i);
*/

void	li_swap_bonds(t_data *data, size_t i, size_t pos_a, size_t pos_b)
{
	size_t	j;

	j = 0;
	while (j < (*(data->map + i))->nb_of_bonds)
	{
		if (*((*(data->map + i))->bond_sum + j) == pos_a)
		{
			*((*(data->map + i))->bond_sum + j) = pos_b;
		}
		else if (*((*(data->map + i))->bond_sum + j) == pos_b)
		{
			*((*(data->map + i))->bond_sum + j) = pos_a;
		}
		j++;
	}
}

/*
** La fonction 'li_erase_room', appelee avec la salle 'S' :
** - Pour chaque salle I, si la salle 'I' est reliee a la salle 'S' ou
**   a l'avant-derniere salle 'Y' du tableau :
**     - interverti dans le tableau des liaisons de 'I' les positions
**       des salles 'S' et 'Y'
**     - interverti dans le sommaire des liaisons de 'I' les positions
**       des salles 'S' et 'Y'
**     - si 'I' est liee a 'Y' (anciennement 'S') :
**         - interverti dans le sommaire des liaisons de 'I' les positions
**           de 'Y' et de la derniere liaison de ce sommaire
**         - diminue la taille de ce sommaire de '1'
**
** Exemple :
** Erase 'S'
** Dans la salle 'I'
** Sommaire des liaisons : 'C' (3) 'G' (7) 'S' (19) 'Y' (25) 'K' (11)
** data->eff vaut 25
** '7' <-> '25'
** 'G' <-> 'Y'
** '25' <-> '11'
**
**	ft_putstr("Appel de \"\033[32mli_erase_room\033[00m\"\n");
**	li_display_room_info(data, pos);
*/

void	li_erase_room(t_data *data, size_t pos)
{
	size_t	i;
	size_t	last_neighbour;
	size_t	tmp;

	ft_putstr("Appel de \"\033[32mli_erase_room\033[00m\"\n");
	li_display_room_info(data, pos);
	if (!(pos == 0 || pos == data->size - 1))
	{
//		li_print_map(data);
		(data->eff)--;
		data->wit = 1;
		i = 0;
		while (i < data->size)
		{
			if (*((*(data->map + i))->pipes + pos) == 1
					|| *((*(data->map + i))->pipes + data->eff) == 1)
			{
				tmp = *((*(data->map + i))->pipes + pos);
				*((*(data->map + i))->pipes + pos) = *((*(data->map + i))->pipes + data->eff);
				*((*(data->map + i))->pipes + data->eff) = tmp;
				li_swap_bonds(data, i, pos, data->eff);
				if (*((*(data->map + i))->pipes + data->eff) == 1)
				{
					last_neighbour = *((*(data->map + i))->bond_sum + (*(data->map + i))->nb_of_bonds - 1);
					li_swap_bonds(data, i, data->eff, last_neighbour);
					((*(data->map + i))->nb_of_bonds)--;
				}
			}
			i++;
		}
		li_swap_map(data, pos, data->eff);
	}
}

/*
**	ft_putstr("Appel de \"\033[31mli_swap_rooms\033[00m\"\n");
**	ft_putstr((*(data->map + pos_a))->name);
**	ft_putstr(" | ");
**	ft_putstr((*(data->map + pos_b))->name);
**	ft_putchar('\n');
*/

void	li_swap_rooms(t_data *data, size_t pos_a, size_t pos_b)
{
	size_t	i;
	size_t	tmp;

	ft_putstr("Appel de \"\033[31mli_swap_rooms\033[00m\"\n");
	ft_putstr((*(data->map + pos_a))->name);
	ft_putstr(" | ");
	ft_putstr((*(data->map + pos_b))->name);
	ft_putchar('\n');
	i = 0;
	while (i < data->size)
	{
		if (*((*(data->map + i))->pipes + pos_a) == 1
				|| *((*(data->map + i))->pipes + pos_b) == 1)
		{
			tmp = *((*(data->map + i))->pipes + pos_a);
			*((*(data->map + i))->pipes + pos_a) = *((*(data->map + i))->pipes + pos_b);
			*((*(data->map + i))->pipes + pos_b) = tmp;
			li_swap_bonds(data, i, pos_a, pos_b);
		}
		i++;
	}
	li_swap_map(data, pos_a, pos_b);
}
