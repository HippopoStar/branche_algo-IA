/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:00:57 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/17 01:06:14 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*emplacement;

	if (!(emplacement = (void *)malloc(size * sizeof(unsigned char))))
		return (NULL);
	ft_bzero(emplacement, size);
	return (emplacement);
}
