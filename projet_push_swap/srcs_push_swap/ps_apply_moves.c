/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_apply_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 02:20:07 by lcabanes          #+#    #+#             */
/*   Updated: 2019/01/19 02:23:48 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ps_apply_moves(t_nb *stacks[2], char *command)
{
	if (*(command + 0) == 's' && ft_strlen(command) == 2)
	{
		if (*(command + 1) == 'a' || *(command + 1) == 's')
			ft_swap(stacks, 'a');
		if (*(command + 1) == 'b' || *(command + 1) == 's')
			ft_swap(stacks, 'b');
	}
	else if (*(command + 0) == 'p' && ft_strlen(command) == 2)
		(*(command + 1) == 'a') ?
			ft_push(stacks, 'a') : ft_push(stacks, 'b');
	else if (*(command + 0) == 'r' && ft_strlen(command) == 2)
	{
		if (*(command + 1) == 'a' || *(command + 1) == 'r')
			ft_rotate(stacks, 'a');
		if (*(command + 1) == 'b' || *(command + 1) == 'r')
			ft_rotate(stacks, 'b');
	}
	else if (!(ft_strncmp(command, "rr", 2)) && ft_strlen(command) == 3)
	{
		if (*(command + 2) == 'a' || *(command + 2) == 'r')
			ft_reverse_rotate(stacks, 'a');
		if (*(command + 2) == 'b' || *(command + 2) == 'r')
			ft_reverse_rotate(stacks, 'b');
	}
}
