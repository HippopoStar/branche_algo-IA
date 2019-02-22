/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:37:45 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 01:41:54 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	index;
	size_t	compteur;

	index = 0;
	compteur = 0;
	while (*(s + index) == c)
	{
		index++;
	}
	while (*(s + index) != '\0')
	{
		i = 0;
		while (*(s + index + i) != c && *(s + index + i) != '\0')
		{
			i++;
		}
		while (*(s + index + i) == c)
		{
			i++;
		}
		index = index + i;
		compteur++;
	}
	return (compteur);
}

static size_t	fill_word(char **split, const char *s, char c)
{
	size_t	i;
	size_t	word_length;

	word_length = 0;
	while (*(s + word_length) != c && *(s + word_length) != '\0')
	{
		word_length++;
	}
	if (!(*(split + 0) = (char *)malloc((word_length + 1) * sizeof(char))))
		return (word_length);
	i = 0;
	while (i < word_length)
	{
		*(*(split + 0) + i) = *(s + i);
		i++;
	}
	*(*(split + 0) + word_length) = '\0';
	return (word_length);
}

static char		**aux_ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	word_place;
	size_t	i;

	if (!(split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (*(s + i) == c)
	{
		i++;
	}
	word_place = 0;
	while (*(s + i) != '\0')
	{
		i = i + fill_word(&(*(split + word_place)), (s + i), c);
		word_place++;
		while (*(s + i) == c)
		{
			i++;
		}
	}
	*(split + word_place) = NULL;
	return (split);
}

char			**ft_strsplit(char const *s, char c)
{
	return ((s != NULL) ? aux_ft_strsplit(s, c) : NULL);
}
