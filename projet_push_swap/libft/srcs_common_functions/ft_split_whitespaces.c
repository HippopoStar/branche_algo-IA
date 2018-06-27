/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:28:11 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/25 15:48:03 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_characters(char *str)
{
	int i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	return (i + 2);
}

static int	compt_mots(char *str)
{
	int		i;
	int		temp;
	int		nbr_mots;

	nbr_mots = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			i++;
		}
		if (str[i] != '\0')
		{
			temp = count_characters(&str[i] - 2);
			nbr_mots = nbr_mots + temp;
			i = i + temp;
		}
		if (str[i] != '\0')
		{
			i++;
		}
	}
	return (nbr_mots);
}

static void	attribute(char *dest, char *src, int word_size)
{
	int i;

	i = 0;
	while (i < word_size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[word_size] = '\0';
}

static char	**aux_whitespaces(char **split, char *str)
{
	int i;
	int word_size;
	int compteur;

	compteur = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] != '\0')
		{
			word_size = count_characters(&str[i]);
			split[compteur] = (char *)malloc(word_size * sizeof(char));
			if ((split[compteur]) == NULL)
				return (0);
			attribute(split[compteur], &str[i], word_size - 2);
			compteur++;
			i = i + (word_size - 2);
		}
		if (str[i] != '\0')
			i++;
	}
	split[compteur] = NULL;
	return (split);
}

char		**ft_split_whitespaces(char *str)
{
	char	**split;
	int		nbr_mots;

	nbr_mots = compt_mots(str);
	if (!(split = (char **)malloc((nbr_mots + 1) * sizeof(char *))))
		return (0);
	return (aux_whitespaces(split, str));
}
