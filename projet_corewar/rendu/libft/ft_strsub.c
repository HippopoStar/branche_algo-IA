/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:29:23 by cmiran            #+#    #+#             */
/*   Updated: 2019/06/06 01:41:44 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Alloue (avec malloc(3)) et retourne la copie “fraiche” d’un tronçon de la
** chaine de caractères passée en paramètre. Le tronçon commence à l’index
** start et à pour longueur len. Si start et len ne désignent pas un tronçon
** de chaine valide, le comportement est indéterminé. Si l’allocation échoue,
** la fonction renvoie NULL.
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(sstr = (char *)malloc(sizeof(*sstr) * len + 1)))
		return (NULL);
	i = 0;
	while (s[start] && len--)
		sstr[i++] = s[start++];
	sstr[i] = '\0';
	return (sstr);
}
