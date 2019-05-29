/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_move_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:49:03 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/29 21:31:13 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		li_allocate_ant_tab(t_data *data)
{
	size_t	i;

	if (!(data->ant_tab = (t_ant *)malloc(data->ants * sizeof(t_ant))))
		return (0);
	i = 0;
	while (i < (size_t)data->ants)
	{
		(*(data->ant_tab + i)).pos_x = i % (data->best_route + 1);
		(*(data->ant_tab + i)).pos_y = 1;
		li_size_ttoa(i + 1, (*(data->ant_tab + i)).to_print, data->color);
		i++;
	}
	return (1);
}

void	aux_li_move_ants(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < (size_t)data->ants && (*(data->ant_tab + i)).pos_y != 1)
	{
		if ((*(data->ant_tab + i)).pos_y < *(*(*(data->routes + data->best_route) + (*(data->ant_tab + i)).pos_x) + data->size))
		{
			li_get_output(data, (char *)(*(data->ant_tab + i)).to_print);
			li_get_output(data, (*(data->map + *(*(*(data->routes + data->best_route) + (*(data->ant_tab + i)).pos_x) + (*(data->ant_tab + i)).pos_y)))->name);
			((*(data->ant_tab + i)).pos_y)++;
		}
		i++;
	}
	j = 0;
	while (j <= data->best_route && i + j < (size_t)data->ants)
	{
		li_get_output(data, (char *)(*(data->ant_tab + i + j)).to_print);
		li_get_output(data, (*(data->map + *(*(*(data->routes + data->best_route) + (*(data->ant_tab + i + j)).pos_x) + (*(data->ant_tab + i + j)).pos_y)))->name);
		((*(data->ant_tab + i + j)).pos_y)++;
		j++;
	}
}

int		li_move_ants(t_data *data)
{
//	size_t	calls;
	size_t	i;
//	size_t	j;

	if (!(li_allocate_ant_tab(data)))
		return (0);
	i = 1;
	while (i <= data->best_steps)
	{
//		calls = i * (data->best_index + 1);
//		j = 0;
//		while (j < calls)
//		{
			aux_li_move_ants(data);
			li_get_output(data, "\n");
//			j++;
//		}
		i++;
	}
	return (1);
}

