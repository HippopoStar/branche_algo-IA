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

int		li_match_ants(t_input **input, t_data *data)
{
	size_t	i;
	int		wit;

	while (!(*((*input)->line + 0) == '\0'))
	{
		if (*((*input)->line + 0) == '#')
		{
			(*input) = (*input)->next;
		}
		else
		{
			wit = 0;
			i = 0;
			while (*((*input)->line + i) != '\0')
			{
				if (!ft_is_digit(*((*input)->line + i)))
					return (0);
				if (*((*input)->line + i) != '0')
					wit = 1;
			}
			data->ants = ft_atoi((*input)->line);
			return ((!(data->ants == 0 && wit == 1)) ? 1 : 0);
		}
	}
	return (0);
}

int		li_match_rooms(t_input **input, t_data *data)
{
	size_t	i;
	int		wit;
	t_room	**tmp;

	tmp = &(data->rooms);
	wit = 0;
	while (!(*((*input)->line + 0) == '\0') && wit % 5 != 0)
	{
		if (!tmp && !((*tmp) = (t_room *)malloc(sizeof(t_room))))
			return (0);
		if (*((*input)->line + 0) == '#')
		{
			if (!ft_strcmp((*input)->line, "##start"))
				(*tmp)->role = 2;
			if (!ft_strcmp((*input)->line, "##end"))
				(*tmp)->role = 3;
		}
		else
		{
			aux_li_match_rooms(*tmp, (*input)->line) ? return (0) : wit = wit * (*tmp)->role;
		}
		if ((*tmp)->role != 5)
			(*input) = (*input)->next;
		tmp = &((*tmp)->next);
	}
	return (wit == 30 ? 1 : 0);
}

int		li_parse_input(t_data *data)
{
	if (!li_match_ants(&(data->input), data))
		return (0);
	else if (!li_match_rooms(&(data->input), data))
		return (0);
	else if (!li_match_pipes(&(data->input), data))
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
