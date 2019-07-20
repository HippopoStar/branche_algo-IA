/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:23:03 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/22 14:45:02 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Prend en paramètre l’adresse d’un pointeur sur un maillon et libère la
** mémoire du contenu de ce maillon avec la fonction del passée en paramètre
** puis libère la mémoire du maillon en lui même avec free(3). La mémoire du
** champ next ne doit en aucun cas être libérée. Pour terminer, le pointeur
** sur le maillon maintenant libéré doit être mis à NULL (de manière
** similaire à la fonction ft_memdel).
*/

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst)
		return ;
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
}
