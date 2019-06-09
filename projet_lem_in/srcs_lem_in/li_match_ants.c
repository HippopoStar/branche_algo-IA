/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_match_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:33:37 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/09 16:07:21 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** 'li_match_ants' saute les eventuels commentaires precedents la declaration
** du nombre de fourmis, puis interprete le nombre de fourmis
** en verifiaiant que la ligne concernee ne contient rien d'autre
*/

int		li_match_ants(t_input **read, t_data *data)
{
	size_t	i;
	int		wit;

	while (*read)
	{
		if (*((*read)->line + 0) == '#')
		{
			*read = (*read)->next;
		}
		else
		{
			i = 0;
			wit = ((ft_is_int((*read)->line, &i, &(data->ants))
						&& data->ants > 0 && *((*read)->line + i) == '\0')
					? 1 : 0);
			*read = (*read)->next;
			return (wit);
		}
	}
	return (0);
}
