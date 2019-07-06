/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:26:20 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 01:46:01 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	aux_ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (*(s + i) != '\0')
	{
		f(i, &(*(s + i)));
		i++;
	}
}

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	if (s != NULL && f != NULL)
	{
		aux_ft_striteri(s, f);
	}
}
