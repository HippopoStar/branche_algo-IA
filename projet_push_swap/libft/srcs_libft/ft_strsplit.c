/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:37:45 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/24 16:56:09 by lcabanes         ###   ########.fr       */
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
		return (0);
	i = 0;
	while (i < word_length)
	{
		*(*(split + 0) + i) = *(s + i);
		i++;
	}
	*(*(split + 0) + word_length) = '\0';
	return (word_length);
}

static int		aux_ft_strsplit(char const *s, char c, char **split)
{
	size_t	word_place;
	size_t	i;
	size_t	ret_val;

	i = 0;
	while (*(s + i) == c)
	{
		i++;
	}
	word_place = 0;
	while (*(s + i) != '\0')
	{
		if ((ret_val = fill_word(&(*(split + word_place)), (s + i), c)) == 0)
			return (0);
		i = i + ret_val;
		word_place++;
		while (*(s + i) == c)
		{
			i++;
		}
	}
	*(split + word_place) = NULL;
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	i;

	if (s == NULL)
	{
		return (NULL);
	}
	if (!(split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *))))
	{
		return (NULL);
	}
	if (aux_ft_strsplit(s, c, split) == 0)
	{
		i = 0;
		while (*(split + i) != NULL)
		{
			free(*(split + i));
			i++;
		}
		free(split);
		return (NULL);
	}
	return (split);
}
