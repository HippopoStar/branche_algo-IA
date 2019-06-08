/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:28:11 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/25 18:51:22 by lcabanes         ###   ########.fr       */
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
	return (i);
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
			temp = count_characters(&str[i]);
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

static int	aux_whitespaces(char **split, char *str)
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
			split[compteur] = (char *)malloc((word_size + 1) * sizeof(char));
			if ((split[compteur]) == 0)
				return (0);
			attribute(split[compteur], &str[i], word_size);
			compteur++;
			i = i + (word_size);
		}
		if (str[i] != '\0')
			i++;
	}
	split[compteur] = 0;
	return (1);
}

char		**ft_split_whitespaces(char *str)
{
	char	**split;
	int		nbr_mots;
	int		ret_val;
	int		i;

	nbr_mots = compt_mots(str);
	if (!(split = (char **)malloc((nbr_mots + 1) * sizeof(char *))))
		return (0);
	ret_val = aux_whitespaces(split, str);
	if (ret_val == 0)
	{
		i = 0;
		while (*(split + i) == 0)
		{
			free(*(split + i));
			i++;
		}
		free(split);
		return (0);
	}
	return (split);
}
