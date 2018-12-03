/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:44:50 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 01:51:46 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	aux_ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}

void		ft_putstr(char const *s)
{
	if (s != NULL)
	{
		aux_ft_putstr(s);
	}
}
