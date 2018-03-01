/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:10:01 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 01:50:07 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	aux_ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}

void		ft_memdel(void **ap)
{
	if (ap != NULL && *ap != NULL)
	{
		aux_ft_memdel(ap);
	}
}
