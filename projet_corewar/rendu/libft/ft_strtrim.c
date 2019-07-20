/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:42:40 by cmiran            #+#    #+#             */
/*   Updated: 2017/11/29 16:33:16 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Alloue (avec malloc(3)) et retourne une copie de la chaine passée en
** paramètre sans les espaces blancs au debut et à la fin de cette chaine,
** On considère comme espaces blancs les caractères ’ ’, ’\n’ et ’\t’.
** Si s ne contient pas d’espaces blancs au début ou à la fin, la fonction
** renvoie une copie de s. Si l’allocation echoue, la fonction renvoie NULL.
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		len--;
		i++;
	}
	if (len < 1)
		len = 0;
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	s += i;
	i = 0;
	while (i < len)
		str[i++] = *s++;
	str[i] = '\0';
	return (str);
}
