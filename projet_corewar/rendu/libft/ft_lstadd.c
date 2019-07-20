/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:11:16 by cmiran            #+#    #+#             */
/*   Updated: 2017/11/29 16:56:09 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ajoute l’élément new en tête de la liste.
*/

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}
