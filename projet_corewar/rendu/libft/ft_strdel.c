/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:08:01 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/19 16:00:27 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Prend en paramètre l’adresse d’une chaine de caractères qui doit être
** libérée avec free(3) et son pointeur mis à NULL.
*/

#include "libft.h"

void	ft_strdel(char **str)
{
	if (!*str)
		return ;
	free(*str);
	*str = NULL;
}
