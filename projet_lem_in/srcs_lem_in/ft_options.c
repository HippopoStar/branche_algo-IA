/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 22:34:03 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/07 22:34:05 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description de la fonction 'ft_options' :
** Parametres 1 & 2 : argc & argv tels que passes en arguments au programme
** Parametre 3 : (const char *) liste des options autorisees
** Parametre 4 : (int) '0' si seulement des options sont autorisees, '1' sinon
**
** Renvoie '-1' en cas de passage d'un mauvais parametre ou
** d'une option enoncee plus d'une fois
**
** Note :
** On aurait pu l'implementer de maniere a ce qu'elle appelle d'elle-meme
** une fonction <usage> passee en parametre sous la forme d'un '(void *)f'
** en cas d'erreur
** Pour cela, il aurait fallu par exemple remplacer l'entier
** donnant l'information sur l'autorisation de passer des arguments
** n'etant pas des options par un caractere '0' ou '1' au debut de
** la chaine listant les caracteres d'options valides
*/

static int	aux_ft_options(char *av, int *options, const char *allowed_opt)
{
	size_t	i;
	char	c;

	i = 1;
	while (!((c = *(av + i)) == '\0'))
	{
		if (!('a' <= c && c <= 'z') || !ft_strchr(allowed_opt, (int)c))
		{
			return (0);
		}
		else
		{
			if (((*options) >> (c - 'a')) % 2 == 0)
			{
				*options = (*options) + (1 << (c - 'a'));
			}
			else
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int		ft_options(int argc, char **argv, const char *allowed_opt, int allow_non_opt)
{
	int		options;
	int		i;

	options = 0;
	i = 1;
	while (i < argc)
	{
		if (!(*(*(argv + i) + 0) == '-') || *(*(argv + i) + 1) == '\0')
		{
			if (!allow_non_opt)
			{
				return (-1);
			}
		}
		else
		{
			if (!aux_ft_options(*(argv + i), &options, allowed_opt))
			{
				return (-1);
			}
		}
		i++;
	}
	return (options);
}
