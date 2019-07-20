/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 20:33:40 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/08 17:53:32 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Alloue (avec malloc(3)) et retourne un tableau de chaines de caractères
** “fraiches” (toutes terminées par un ’\0’, le tableau également donc)
** résultant de la découpe de s selon le caractère c. Si l’allocation echoue,
** la fonction retourne NULL.
** Exemple : ft_strsplit("*salut*les***etudiants*", ’*’) renvoie le tableau
** ["salut", "les", "etudiants"].
*/

#include "libft.h"

static size_t	ft_x(const char *s, char c, size_t i)
{
	size_t	x;

	x = 0;
	while (s[i] != c && s[i])
	{
		i++;
		x++;
	}
	return (x);
}

static size_t	ft_y(const char *s, char c, size_t i)
{
	size_t	y;

	y = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			y++;
		while (s[i] != c && s[i])
			i++;
	}
	return (y);
}

static char		*ft_strpullr(const char *s, char c, size_t *i)
{
	char	*str;
	size_t	j;

	if (!(str = (char *)malloc(sizeof(*str) * ft_x(s, c, *i) + 1)))
		return (NULL);
	j = 0;
	while (s[*i] != c && s[*i])
	{
		str[j++] = s[*i];
		*i += 1;
	}
	str[j] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	if (!s || !c)
		return (NULL);
	i = 0;
	if (!(tab = (char **)malloc(sizeof(*tab) * (ft_y(s, c, i) + 1))))
		return (NULL);
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			if (!(tab[j++] = ft_strpullr(s, c, &i)))
			{
				ft_freetab(&tab);
				return (NULL);
			}
	}
	tab[j] = NULL;
	return (tab);
}
