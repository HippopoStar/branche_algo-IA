/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_match_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:33:37 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/12 17:57:21 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** 'li_match_ants' saute les eventuels commentaires precedents la declaration
** du nombre de fourmis, puis interprete le nombre de fourmis
** en verifiaiant que la ligne concernee ne contient rien d'autre
*/

int		li_match_ants(t_data *data, char *line)
{
	size_t	len;

	len = 0;
	return ((ft_is_int(line, &len, &(data->ants)) && data->ants >= 0
				&& *(line + len) == '\0') ? 1 : 0);
}
