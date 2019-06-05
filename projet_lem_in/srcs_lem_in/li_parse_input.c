/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:28:04 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/05 20:43:51 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		li_parse_input(t_data *data)
{
	data->read = data->input;
	if (!li_match_ants(&(data->read), data))
		return (0);
	ft_putstr("\"li_match_ants\" OK !\n");
	/*else*/ if (!li_match_rooms(&(data->read), data))
		return (0);
	ft_putstr("\"li_match_rooms\" OK !\n");
	/*else*/ if (!li_allocate_map(data))
		return (0);
	ft_putstr("\"li_allocate_map\" OK !\n");
	/*else*/ if (!li_match_pipes(&(data->read), data))
		return (0);
	ft_putstr("\"li_match_pipes\" OK !\n");
	/*else*/ if (!li_shorten_map_pipes(data))
		return (0);
	ft_putstr("\"li_shorten_map_pipes\" OK !\n");
	/*else*/
		return (1);
}

int		li_get_input(t_data *data, t_input **input)
{
	int		ret_gnl;
	t_input	*tmp;

	if (!((*input) = (t_input *)malloc(sizeof(t_input))))
		return (0);
	tmp = *input;
	while ((ret_gnl = get_next_line_backslash_zero(0, &(tmp->line))) == 1)
	{
		li_get_output(data, tmp->line);
		li_get_output(data, "\n");
		if (!(tmp->next = (t_input *)malloc(sizeof(t_input))))
			return (0);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	li_print_output(data);
	ft_putchar('\n');
	return ((ret_gnl == 0) ? 1 : 0);
}
