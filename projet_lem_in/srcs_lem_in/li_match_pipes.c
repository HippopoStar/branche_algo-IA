/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_match_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:33:47 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/17 17:52:07 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		li_match_pipe(t_data *data, char *str)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	while (*(str + i) != '-' && *(str + i) != '\0')
	{
		i++;
	}
	tmp = (*(str + i) == '-') ? (str + i + 1) : (str + i);
	*(str + i) = '\0';
	i = 0;
	while (i < data->size && ft_strcmp((*(data->map + i))->name, str))
	{
		i++;
	}
	j = 0;
	while (j < data->size && ft_strcmp((*(data->map + j))->name, tmp))
	{
		j++;
	}
	if (i == data->size || j == data->size || i == j)
		return (0);
	*((*(data->map + i))->pipes + j) = 1;
	*((*(data->map + j))->pipes + i) = 1;
	return (1);
}

int		li_match_pipes(t_input **read, t_data *data)
{
	while (*((*read)->line + 0) != '\0')
	{
		if (!(*((*read)->line + 0) == '#') \
				&& !li_match_pipe(data, (*read)->line))
		{
			return (0);
		}
		*read = (*read)->next;
	}
	return (((*read)->next == NULL) ? 1 : 0);
}
