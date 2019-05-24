/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:15:32 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/24 15:32:42 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** L'execution de 'ps_position' se passe en partant du postulat de depart
** que la pile 'A' n'est pas vide, et que le nombre recherche se trouve bel
** et bien dans la liste triee elaboree plus tot dans le programme
*/

size_t	ps_position(t_ps *data)
{
	size_t	i;

	i = 0;
	while (*(data->sorted + i) != (*(data->stacks + 0))->nb)
	{
		i++;
	}
	return (i);
}

void	ps_swap_instructions(t_ps *data)
{
	int		instruction;

	instruction = 1;
	if ((*(data->stacks + 0))->nb > ((*(data->stacks + 0))->next)->nb)
	{
		instruction = 2 * instruction;
	}
	if ((*(data->stacks + 1) != NULL && (*(data->stacks + 1))->next != NULL) \
			&& ((*(data->stacks + 1))->nb < ((*(data->stacks + 1))->next)->nb))
	{
		instruction = 3 * instruction;
	}
	if (instruction % 6 == 0)
		ps_print_and_do(data, "ss");
	else if (instruction % 2 == 0)
		ps_print_and_do(data, "sa");
	else if (instruction % 3 == 0)
		ps_print_and_do(data, "sb");
}
