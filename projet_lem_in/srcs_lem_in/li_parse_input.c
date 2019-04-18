/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:28:04 by lcabanes          #+#    #+#             */
/*   Updated: 2019/02/26 12:57:05 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		li_parse_input(t_data *data)
{
	data->read = data->input;
	if (!li_match_ants(&(data->read), data))
		return (0);
	else if (!li_match_rooms(&(data->read), data))
		return (0);
	else if (!li_allocate_map(data))
		return (0);
	else if (!li_match_pipes(&(data->read), data))
		return (0);
	else
		return (1);
}

int		li_get_input(t_input **input)
{
	int		ret_gnl;

	if (!((*input) = (t_input *)malloc(sizeof(t_input))))
		return (0);
	while ((ret_gnl = get_next_line_backslash_zero(0, &((*input)->line))) == 1)
	{
		if (!((*input)->next = (t_input *)malloc(sizeof(t_input))))
			return (0);
		(*input) = (*input)->next;
	}
	(*input)->next = NULL;
	return ((ret_gnl == 0) ? 1 : 0);
}
