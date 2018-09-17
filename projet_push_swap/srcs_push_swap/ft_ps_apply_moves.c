/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_apply_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:21:52 by lcabanes          #+#    #+#             */
/*   Updated: 2018/09/17 16:22:45 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_ps_apply_moves(t_nb **stacks, char *command)
{
	if (*(command + 0) == 's' && ft_strlen(command) == 2)
	{
		if (*(command + 1) == 'a' || *(command + 1) == 's')
			ft_ps_swap(stacks, 'a');
		if (*(command + 1) == 'b' || *(command + 1) == 's')
			ft_ps_swap(stacks, 'b');
	}
	else if (*(command + 0) == 'p' && ft_strlen(command) == 2)
	{
		if (*(command + 1) == 'a')
			ft_ps_push(stacks, 'a');
		else if (*(command + 1) == 'b')
			ft_ps_push(stacks, 'b');
	}
	else if (*(command + 0) == 'r' && ft_strlen(command) == 2)
	{
		if (*(command + 1) == 'a' || *(command + 1) == 'r')
			ft_ps_rotate(stacks, 'a');
		if (*(command + 1) == 'b' || *(command + 1) == 'r')
			ft_ps_rotate(stacks, 'b');
	}
	else if (!(ft_strncmp(command, "rr", 2)) && ft_strlen(command) == 3)
	{
		if (*(command + 2) == 'a' || *(command + 2) == 'r')
			ft_ps_reverse_rotate(stacks, 'a');
		if (*(command + 2) == 'b' || *(command + 2) == 'r')
			ft_ps_reverse_rotate(stacks, 'b');
	}
}
