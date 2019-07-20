/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:36:10 by cmiran            #+#    #+#             */
/*   Updated: 2017/11/29 16:41:28 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applique la fonction f à chaque caractère de la chaine de caractères
** passée en paramètre. Chaque caractère est passé par adresse à la
** fonction f afin de pouvoir être modifié si nécéssaire.
*/

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	if (!s || !f)
		return ;
	while (s[0])
		f(s++);
}
