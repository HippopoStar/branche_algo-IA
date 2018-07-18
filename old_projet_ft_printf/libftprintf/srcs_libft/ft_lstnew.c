/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 01:55:18 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/17 02:08:25 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_link;

	if (!(new_link = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new_link->content = NULL;
		new_link->content_size = 0;
	}
	else
	{
		if (!(new_link->content = (void *)malloc(content_size)))
			return (NULL);
		new_link->content = ft_memcpy(new_link->content, content, content_size);
		new_link->content_size = content_size;
	}
	new_link->next = NULL;
	return (new_link);
}
