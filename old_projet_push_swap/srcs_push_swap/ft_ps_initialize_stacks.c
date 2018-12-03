/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_initialize_stacks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 10:51:35 by lcabanes          #+#    #+#             */
/*   Updated: 2018/09/19 10:51:40 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_initialize_stacks(t_nb ***stacks_adress)
{
	if (!((*stacks_adress) = (t_nb **)malloc(2 * sizeof(t_nb *))))
		exit(-1);
	*((*stacks_adress) + 0) = NULL;
	*((*stacks_adress) + 1) = NULL;
}
