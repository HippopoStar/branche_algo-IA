/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:35:59 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 01:55:01 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	aux_ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}

void		ft_putendl(char const *s)
{
	if (s != NULL)
	{
		aux_ft_putendl(s);
	}
}
