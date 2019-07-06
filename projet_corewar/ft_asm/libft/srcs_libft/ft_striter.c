/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:23:21 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 01:45:43 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	aux_ft_striter(char *s, void (*f)(char *))
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
	{
		f(&(*(s + i)));
		i++;
	}
}

void		ft_striter(char *s, void (*f)(char *))
{
	if (s != NULL && f != NULL)
	{
		aux_ft_striter(s, f);
	}
}
