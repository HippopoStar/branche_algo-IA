/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 02:48:17 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/26 01:42:43 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*current;
	t_list	*next;

	if (lst == NULL)
		return (NULL);
	else
	{
		if (!(new_list = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		current = new_list;
		while (lst->next != NULL)
		{
			*current = *(f(lst));
			if (!(next = (t_list *)malloc(sizeof(t_list))))
				return (NULL);
			current->next = next;
			current = next;
			lst = lst->next;
		}
		*current = *f(lst);
		current->next = NULL;
	}
	return (new_list);
}
