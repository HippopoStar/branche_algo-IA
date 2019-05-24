/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 01:24:59 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/24 14:35:17 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_valid_input(char *line)
{
	return ((!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb")
				|| !ft_strcmp(line, "ss") || !ft_strcmp(line, "pa")
				|| !ft_strcmp(line, "pb") || !ft_strcmp(line, "ra")
				|| !ft_strcmp(line, "rb") || !ft_strcmp(line, "rr")
				|| !ft_strcmp(line, "rra") || !ft_strcmp(line, "rrb")
				|| !ft_strcmp(line, "rrr")) ? 1 : 0);
}

/*
** Allocation dynamique de memoire dans 'ps_get_input'
** ('get_next_line_backslash_zero' / 'malloc')
*/

int		ps_get_input(t_input **input)
{
	int		ret_gnl;
	char	*line;

	while ((ret_gnl = get_next_line_backslash_zero(0, &line)) == 1)
	{
		if (ps_valid_input(line))
		{
			if (!((*input) = (t_input *)malloc(sizeof(t_input))))
				return (0);
			ft_strcpy((*input)->inst, line);
			free(line);
			(*input)->next = NULL;
			input = &((*input)->next);
		}
		else
		{
			free(line);
			return (0);
		}
	}
	if (ret_gnl == 0)
	{
		free(line);
	}
	return ((ret_gnl == 0) ? 1 : 0);
}
