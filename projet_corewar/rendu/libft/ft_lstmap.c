/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:33:20 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/03 14:44:29 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parcourt la liste lst en appliquant à chaque maillon la fonction f et crée
** une nouvelle liste “fraiche” avec malloc(3) résultant des applications
** successives. Si une allocation échoue, la fonction renvoie NULL.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;
	t_list	*tmp;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	elem = f(lst);
	if (!(tmp = ft_lstnew(elem->content, elem->content_size)))
		return (NULL);
	new = tmp;
	lst = lst->next;
	while (lst)
	{
		elem = f(lst);
		if (!(tmp->next = ft_lstnew(elem->content, elem->content_size)))
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	free(elem);
	return (new);
}
