/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 22:33:22 by cmiran            #+#    #+#             */
/*   Updated: 2019/06/30 22:35:47 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t size)
{
	void	*mem;

	if (!(mem = (void *)realloc(src, sizeof(void) * size)))
		return (NULL);
	return (mem);
}
