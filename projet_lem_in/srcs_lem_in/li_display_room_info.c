/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_display_room_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:02:38 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/24 17:52:53 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	li_print_rooms_linked_list(t_data *data)
{
	t_room	*tmp;

	tmp = data->rooms;
	while (tmp != NULL && tmp->name != NULL)
	{
		ft_putchar('|');
		ft_putstr(tmp->name);
		ft_putchar(' ');
		ft_putnbr(tmp->pos_x);
		ft_putchar(' ');
		ft_putnbr(tmp->pos_y);
		ft_putchar('|');
		if (tmp->next != NULL)
		{
			ft_putstr("->");
		}
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void	li_display_room_bonds(t_data *data, size_t i)
{
	size_t	j;

	ft_putstr("liaisons :\n");
	j = 0;
	while (j < (*(data->map + i))->nb_of_bonds)
	{
		ft_putnbr((int)j);
		ft_putstr(". ");
		ft_putstr((*(data->map + *((*(data->map + i))->bond_sum + j)))->name);
		ft_putstr("\t valeur : ");
		ft_putnbr((int)*((*(data->map + i))->pipes
					+ *((*(data->map + i))->bond_sum + j)));
		ft_putchar('\n');
		j++;
	}
}

void	li_display_room_info(t_data *data, size_t i)
{
	ft_putstr("____________________________\n");
	ft_putstr("Index : ");
	ft_putnbr((int)i);
	ft_putstr("\nIdentifiant : ");
	ft_putstr((*(data->map + i))->name);
	ft_putstr("\nPoids : ");
	ft_putnbr((int)(*(data->map + i))->weight);
	ft_putstr("\nVariable 'allowed' : ");
	ft_putnbr((int)(*(data->map + i))->allowed);
	ft_putstr("\nVariable 'exept' : ");
	ft_putnbr((int)(*(data->map + i))->except);
	ft_putstr("\nAbscisse : ");
	ft_putnbr((int)(*(data->map + i))->pos_x);
	ft_putstr("\nOrdonnee : ");
	ft_putnbr((int)(*(data->map + i))->pos_y);
	ft_putstr("\nNombre de liaisons : ");
	ft_putnbr((int)(*(data->map + i))->nb_of_bonds);
	ft_putchar('\n');
	li_display_room_bonds(data, i);
	ft_putstr("____________________________\n");
}
