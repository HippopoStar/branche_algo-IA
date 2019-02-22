/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:07:40 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 01:43:42 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cherche_arrivee(char const *s, size_t index)
{
	size_t	i;

	i = 0;
	while (*(s + index + i) != '\0')
	{
		index = index + i;
		i = 1;
		while (*(s + index + i) == ' ' ||
				*(s + index + i) == '\n' ||
				*(s + index + i) == '\t')
		{
			i++;
		}
	}
	return (index);
}

static char		*aux_ft_strtrim(char const *s)
{
	size_t	i;
	size_t	depart;
	size_t	arrivee;
	size_t	length;
	char	*trim;

	i = 0;
	while (*(s + i) == ' ' || *(s + i) == '\n' || *(s + i) == '\t')
	{
		i++;
	}
	depart = i;
	arrivee = cherche_arrivee(s, depart);
	length = 1 + arrivee - depart;
	if (!(trim = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < length)
	{
		*(trim + i) = *(s + depart + i);
		i++;
	}
	*(trim + i) = '\0';
	return (trim);
}

char			*ft_strtrim(char const *s)
{
	return ((s != NULL) ? aux_ft_strtrim(s) : NULL);
}
