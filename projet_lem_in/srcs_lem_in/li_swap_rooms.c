/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_swap_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:43:53 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/24 19:17:24 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_putstr("Appel de \"li_swap_bonds\"\n");
**	ft_putstr((*(data->map + pos_a))->name);
**	ft_putstr(" | ");
**	ft_putstr((*(data->map + pos_b))->name);
**	ft_putchar('\n');
**	li_display_room_info(data, i);
*/

void	li_swap_bonds(t_data *data, size_t i, size_t pos_a, size_t pos_b)
{
	size_t	j;

	ft_putstr("Appel de \"li_swap_bonds\"\n");
	ft_putstr((*(data->map + pos_a))->name);
	ft_putstr(" | ");
	ft_putstr((*(data->map + pos_b))->name);
	ft_putchar('\n');
	li_display_room_info(data, i);
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
**	ft_putstr("Appel de \"li_erase_room\"\n");
**	li_display_room_info(data, pos);
*/

void	li_erase_room(t_data *data, size_t pos)
{
	size_t	i;
	size_t	last_neighbour;
	size_t	tmp;

	ft_putstr("Appel de \"li_erase_room\"\n");
	li_display_room_info(data, pos);
	if (!(pos == 0 || pos == data->size - 1))
	{
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
					((*(data->map + i))->nb_of_bonds)--;
					last_neighbour = *((*(data->map + i))->bond_sum + (*(data->map + i))->nb_of_bonds);
					li_swap_bonds(data, i, data->eff, last_neighbour);
				}
			}
			i++;
		}
	}
}

/*
**	ft_putstr("Appel de \"li_swap_rooms\"\n");
**	ft_putstr((*(data->map + pos_a))->name);
**	ft_putstr(" | ");
**	ft_putstr((*(data->map + pos_b))->name);
**	ft_putchar('\n');
*/

void	li_swap_rooms(t_data *data, size_t pos_a, size_t pos_b)
{
	size_t	i;
	size_t	tmp;

	ft_putstr("Appel de \"li_swap_rooms\"\n");
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
			*((*(data->map + i))->pipes + pos_a) = tmp;
			li_swap_bonds(data, i, pos_a, pos_b);
		}
		i++;
	}
}
