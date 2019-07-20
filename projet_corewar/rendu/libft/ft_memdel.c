/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:27:23 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/19 15:14:27 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Prend en paramètre l’adresse d’un pointeur dont la zone pointée doit être
** libérée avec free(3), puis le pointeur est mis à NULL.
*/

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (!*ap)
		return ;
	free(*ap);
	*ap = NULL;
}
