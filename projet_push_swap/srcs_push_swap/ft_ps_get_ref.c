/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_get_ref.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 07:19:40 by lcabanes          #+#    #+#             */
/*   Updated: 2018/10/09 07:43:35 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_sort_ref(t_nb *lst_copy)
{
	int		wit;
	t_nb	*tmp;

	wit = 1;
	while (wit == 1)
	{
		wit = 0;
		tmp = lst_copy;
		while (tmp->next != NULL)
		{
			if (tmp->n > (tmp->next)->n)
			{
				wit = tmp->n;
				tmp->n = (tmp->next)->n;
				(tmp->next)->n = wit;
				wit = 1;
			}
			tmp = tmp->next;
		}
	}
}

t_nb	*ft_ps_copy_lst(t_nb *lst)
{
	t_nb	*lst_copy;
	t_nb	*tmp;

	if (lst == NULL || !(lst_copy = (t_nb *)malloc(sizeof(t_nb))))
		return (NULL);
	lst_copy->n = lst->n;
	lst_copy->next = NULL;
	tmp = lst_copy;
	while (lst->next != NULL)
	{
		if (!((tmp->next) = (t_nb *)malloc(sizeof(t_nb))))
		{
			ft_ps_free_lst(lst_copy);
			return (NULL);
		}
		(tmp->next)->n = (lst->next)->n;
		(tmp->next)->next = NULL;
		tmp = tmp->next;
		lst = lst->next;
	}
	return (lst_copy);
}

t_nb	*ft_ps_get_ref(t_nb *init_lst)
{
	t_nb	*lst_ref;

	lst_ref = ft_ps_copy_lst(init_lst);
	ft_ps_sort_ref(lst_ref);
	return (lst_ref);
}
