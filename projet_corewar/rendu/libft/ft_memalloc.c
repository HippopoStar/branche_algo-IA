/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:14:38 by cmiran            #+#    #+#             */
/*   Updated: 2017/11/29 16:46:18 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Alloue (avec malloc(3)) et retourne une zone de mémoire “fraiche”.
** La mémoire allouée est initialisée à 0. Si l’allocation échoue,
** la fonction renvoie NULL.
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	return (ft_memset(mem, 0, size));
}
