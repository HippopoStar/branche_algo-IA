/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:11:07 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/19 04:18:08 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Assigne la valeur ’\0’ à tous les caractères de la chaine passée en
** paramètre.
*/

#include "libft.h"

void	ft_strclr(char *s)
{
	if (!s)
		return ;
	ft_memset(s, '\0', ft_strlen(s));
}
