/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:16:37 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/15 17:55:06 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*emplacement;

	if (!(emplacement = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i <= size)
	{
		*(emplacement + i) = '\0';
		i++;
	}
	return (emplacement);
}
