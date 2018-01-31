/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:40:55 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/15 18:25:02 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	byte;
	unsigned char	*emplacement;

	byte = (unsigned char)c;
	emplacement = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*(emplacement + i) = byte;
		i++;
	}
	return (b);
}
