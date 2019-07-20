/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:37:38 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/22 18:01:45 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Prend en paramètre l’adresse d’un pointeur sur un maillon et libère la
** mémoire de ce maillon et celle de tous ses successeurs l’un après l’autre
** avec del et free(3). Pour terminer, le pointeur sur le premier maillon
** maintenant libéré doit être mis à NULL (de manière similaire à la
** fonction ft_memdel de la partie obligatoire).
*/

#include "libft.h"

/*
** void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
** {
** 	t_list	*list;
** 	t_list	*next;
**
** 	if (!alst)
** 		return ;
** 	list = *alst;
** 	while (list)
** 	{
** 		next = list->next;
** 		ft_lstdelone(&list, del);
** 		list = next;
** 	}
** 	*alst = NULL;
** }
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst)->next)
		ft_lstdel(&(*alst)->next, del);
	ft_lstdelone(alst, del);
}
