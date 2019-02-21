/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_apply_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 02:20:07 by lcabanes          #+#    #+#             */
/*   Updated: 2019/02/21 14:27:10 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ps_apply_moves(t_nb *stacks[2], const char *command)
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

void	ps_reg_m(t_nb *stacks[2], const char *command, t_reg *reg)
{
	if (!ft_strcmp(command, "sa"))
		(reg->sa)++;
	else if (!ft_strcmp(command, "sb"))
		(reg->sb)++;
	else if (!ft_strcmp(command, "ss"))
		(reg->ss)++;
	else if (!ft_strcmp(command, "pa"))
		(reg->pa)++;
	else if (!ft_strcmp(command, "pb"))
		(reg->pb)++;
	else if (!ft_strcmp(command, "ra"))
		(reg->ra)++;
	else if (!ft_strcmp(command, "rb"))
		(reg->rb)++;
	else if (!ft_strcmp(command, "rr"))
		(reg->rr)++;
	else if (!ft_strcmp(command, "rra"))
		(reg->rra)++;
	else if (!ft_strcmp(command, "rrb"))
		(reg->rrb)++;
	else if (!ft_strcmp(command, "rrr"))
		(reg->rrr)++;
	ps_apply_moves(stacks, command);
}

void	ps_print_ando(t_ps *data, const char *command)
{
	t_input	*tmp;

	if (!(tmp = (t_input *)malloc(sizeof(t_input))))
	{
		ps_display_error();
		exit(0);
	}
	ft_strcpy(tmp->inst, command);
	tmp->next = NULL;
	if (data->input == NULL)
	{
		data->input = tmp;
	}
	else
	{
		(data->current_input)->next = tmp;
	}
	data->current_input = tmp;
	ps_apply_moves(data->stacks, command);
}
