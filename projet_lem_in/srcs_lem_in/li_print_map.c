/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:34:35 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/20 21:59:56 by lcabanes         ###   ########.fr       */
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
	while (i < data->max_paths)
	{
		j = 0;
		while (*(*(data->paths + i) + j + 1) == 0)
		{
			j++;
		}
		while (j < data->size)
		{
			ft_putstr((*(data->map + *(*(data->paths + i) + j)))->name);
			if (j != data->size - 1)
			{
				ft_putstr("->");
			}
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	li_print_routes(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (i < data->path_nb)
	{
		j = 0;
		while (j <= i)
		{
			k = 0;
			while (k < data->size)
			{
				ft_putstr((*(data->map + *(*(*(data->routes + i) + j) + k)))->name);
				if (k < data->size - 1)
				{
					ft_putstr("->");
				}
				k++;
			}
			ft_putchar('\n');
			j++;
		}
		i++;
	}
}
