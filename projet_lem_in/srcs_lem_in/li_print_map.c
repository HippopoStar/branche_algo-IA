/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:34:35 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/28 19:27:43 by lcabanes         ###   ########.fr       */
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
			while (k < data->size)
			{
				room_id = *(*(*(data->routes + i) + j) + k);
				ft_putstr((*(data->map + room_id))->name);
				if (k < data->size - 1)
				{
					ft_putstr("->");
				}
				k++;
			}
			ft_putstr(" length : ");
			ft_putnbr((int)(*(*(data->routes + i) + j) + data->size));
			ft_putchar('\n');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
