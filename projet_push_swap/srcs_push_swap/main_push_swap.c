/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:44:12 by lcabanes          #+#    #+#             */
/*   Updated: 2018/10/11 20:48:19 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_ps_aux_left_push_swap(t_nb *stacks[2])
{
	if ((*(stacks + 1))->n <= ((*(stacks + 1))->next)->n)
	{
		if (!(*(stacks + 0) == NULL || (*(stacks + 0))->next == NULL)
				&& (*(stacks + 0))->n >= ((*(stacks + 0))->next)->n)
		{
			ft_ps_swap(stacks, 'a');
			ft_putstr("ss\n");
		}
		else
		{
			ft_putstr("sb\n");
		}
		ft_ps_swap(stacks, 'b');
	}
	ft_ps_push(stacks, 'a');
	ft_putstr("pa\n");
}

void	ft_ps_aux_right_push_swap(t_nb *stacks[2])
{
	if ((*(stacks + 0))->n >= ((*(stacks + 0))->next)->n)
	{
		if (!(*(stacks + 1) == NULL || (*(stacks + 1))->next == NULL)
				&& (*(stacks + 1))->n <= ((*(stacks + 1))->next)->n)
		{
			ft_ps_swap(stacks, 'b');
			ft_putstr("ss\n");
		}
		else
		{
			ft_putstr("sa\n");
		}
		ft_ps_swap(stacks, 'a');
	}
	ft_ps_push(stacks, 'b');
	ft_putstr("pb\n");
}

void	ft_ps_push_swap(t_nb *stacks[2], t_nb *sorted_refs[2], char c)
{
	int		ret;

	ret = ft_ps_check_order(stacks, sorted_refs, c);
	if (ret == 2)
	{
		while (*(stacks + 1) != NULL)
		{
			ft_ps_push(stacks, 'a');
			ft_putstr("pa\n");
		}
	}
	else if (ret == 1)
	{
		ft_ps_push_swap(stacks, sorted_refs, ((c == 'r') ? 'l' : 'r'));
	}
	else
	{
		(c == 'r') ? ft_ps_aux_right_push_swap(stacks)
			: ft_ps_aux_left_push_swap(stacks);
		ft_ps_push_swap(stacks, sorted_refs, c);
	}
}

int		main(int argc, char **argv)
{
	t_nb	*stacks[2];
	t_nb	*sorted_refs[2];

	*(stacks + 0) = NULL;
	*(stacks + 1) = NULL;
	if (argc > 1)
	{
		ft_ps_parse_parameters(stacks, 0, argc, argv);
		*(sorted_refs + 0) = ft_ps_get_refs(*(stacks + 0), 0);
		if (ft_ps_check_doublons(*(sorted_refs + 0)) == 1)
		{
			ft_putstr("Error\n");
			exit(0);
		}
		*(sorted_refs + 1) = ft_ps_get_refs(*(stacks + 0), 1);
		ft_ps_push_swap(stacks, sorted_refs, 'r');
		ft_ps_free_stacks(stacks);
		ft_ps_free_stacks(sorted_refs);
	}
	return (0);
}
