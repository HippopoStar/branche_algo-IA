/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:49:19 by cmiran            #+#    #+#             */
/*   Updated: 2017/11/29 16:38:06 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applique la fonction f à chaque caractère de la chaine de caractères
** passée en paramètre en précisant son index pour créer une nouvelle chaine
** “fraiche” (avec malloc(3)) résultant des applications successives de f.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mstr;
	size_t	i;

	if (!s || !f)
		return (NULL);
	if (!(mstr = (char *)malloc(sizeof(*mstr) * ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		mstr[i] = f(i, (char)s[i]);
		i++;
	}
	mstr[i] = '\0';
	return (mstr);
}
