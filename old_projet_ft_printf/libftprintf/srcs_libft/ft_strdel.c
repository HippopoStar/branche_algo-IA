/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:20:07 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 01:16:17 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	aux_ft_strdel(char **as)
{
	free(*as);
	*(as) = NULL;
}

void		ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
	{
		aux_ft_strdel(as);
	}
}
