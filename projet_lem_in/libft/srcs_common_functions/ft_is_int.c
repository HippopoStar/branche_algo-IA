/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:32:39 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/17 17:36:00 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description de la fonction 'ft_is_int' :
** Parametre 1 : la chaine de caractere a tester
** Parametre 2 : l'adresse de la position a partir de laquelle travailler
** Parametre 3 : l'adresse de l'entier dans lequel placer la valeure obtenue
**
** Valeur de retour et modification des valeurs
** - Renvoie '1' en cas de lecture un entier tenant dans un 'int', '0' sinon
** - Place dans '*i' l'index du 1er caractere suivant le nombre dans le 1er cas
** - Place dans '*n' la valeur du nombre, ou '0' s'il ne tient pas dans un 'int'
*/

int		ft_is_int(char *str, size_t *i, int *n)
{
	size_t	j;
	int		wit;

	j = *i;
	if (*(str + j) == '+' || *(str + j) == '-')
	{
		j++;
	}
	if (!ft_isdigit(*(str + j)))
		return (0);
	wit = 0;
	while (ft_isdigit(*(str + j)))
	{
		if (*(str + j) != '0')
			wit = 1;
		j++;
	}
	if ((*n = ft_atoi(str + (*i))) == 0 && wit == 1)
		return (0);
	else
	{
		*i = j;
		return (1);
	}
}
