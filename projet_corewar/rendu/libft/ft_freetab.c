/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:33:39 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/22 22:04:06 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetab(char ***tab)
{
	char	**tmp;

	tmp = *tab;
	while (**tab)
	{
		ft_bzero(**tab, ft_strlen(**tab) + 1);
		free(**tab);
		**tab = NULL;
		(*tab)++;
	}
	free(tmp);
}
