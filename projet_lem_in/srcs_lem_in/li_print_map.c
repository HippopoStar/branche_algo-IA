/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:34:35 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/29 16:52:32 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	li_print_map(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->size)
	{
		ft_putchar('(');
		ft_putstr((*(data->map + i))->name);
		ft_putchar(')');
		j = 0;
		while (j < data->size)
		{
			ft_putchar('0' + *((*(data->map + i))->pipes + j));
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

/*
** Rappel :
** Dans le tableau a 2 dimensions 'data->paths'
** les cases '*(*(data->paths + ?) + data->size)'
** doivent contenir l'index de depart de chaque itineraire
*/

void	li_print_paths(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->max_paths && !(*(*(data->paths + i) + data->size) == data->size))
	{
		j = *(*(data->paths + i) + data->size);
		while (j < data->size)
		{
			ft_putstr((*(data->map + *(*(data->paths + i) + j)))->name);
			if (j != data->size - 1)
			{
				ft_putstr("->");
			}
			j++;
		}
		ft_putstr(" *(*(data->paths + ");
		ft_putnbr((int)i);
		ft_putstr(") + data->size) vaut : ");
		ft_putnbr((int)*(*(data->paths + i) + data->size));
		ft_putchar('\n');
		i++;
	}
}

/*
** Rappel :
** Dans le tableau a 3 dimensions 'data->routes'
** les cases '*(*(*(data->routes + ?) + ?) + data->size)'
** doivent contenir le poids total (longueur) de chaque itineraire
**
** D'autre part, au terme de l'execution de 'li_eval_routes'
** les cases '*(*(*(data->routes + ?) + ?) + data->size + 1)'
** doivent contenir le nombre de fourmis a devoir emprunter chaque itineraire
*/

void	li_print_routes(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	room_id;

	i = 0;
	while (i < data->path_nb)
	{
		j = 0;
		while (j <= i)
		{
			k = 0;
			while (k < data->size && !(k > 1 && *(*(*(data->routes + i) + j) + k) == 0))
			{
				room_id = *(*(*(data->routes + i) + j) + k);
				ft_putnbr((int)room_id);
				ft_putstr((*(data->map + room_id))->name);
				if (k < data->size - 1 && *(*(*(data->routes + i) + j) + k + 1) != 0)
				{
					ft_putstr("->");
				}
				k++;
			}
			ft_putstr("\tlength : ");
			ft_putnbr((int)(*(*(*(data->routes + i) + j) + data->size)));
			ft_putstr("\tants : ");
			ft_putnbr((int)(*(*(*(data->routes + i) + j) + data->size + 1)));
			ft_putchar('\n');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
