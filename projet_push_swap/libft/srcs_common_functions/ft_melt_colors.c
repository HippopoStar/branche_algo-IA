/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_melt_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 05:05:53 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/08 05:05:56 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** La fonction 'ft_melt_colors' renvoie l'entier correspondant au code couleur
** exprime par les niveaux d'intensite (0 ~ 255) des 3 couleurs primaires
** passees en parametre, dans le format suivant :
** | 0 | R | G | B |
** +---+---+---+---+
**
** Rappel :
** [0000 0000 | 0000 0001 | 0000 0000 | 0000 0000] = 2^(16)	= 65 536
** [0000 0000 | 0000 0000 | 0000 0001 | 0000 0000] = 2^(8)	= 256
** [0000 0000 | 0000 0000 | 0000 0000 | 0000 0001] = 2^(0)	= 1
*/

int		ft_melt_colors(int red, int green, int blue)
{
	return ((65536 * red) + (256 * green) + blue);
}
