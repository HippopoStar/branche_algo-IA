/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:59:37 by cmiran            #+#    #+#             */
/*   Updated: 2017/11/30 17:46:39 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Affiche la chaine s sur la sortie standard.
*/

#include "libft.h"

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	write(1, (const char *)s, ft_strlen(s));
}
