/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_display_stacks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:40:31 by lcabanes          #+#    #+#             */
/*   Updated: 2018/10/11 16:23:46 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_ps_stack_length(t_nb *stack)
{
	int		i;

	if (stack == NULL)
	{
		return (0);
	}
	i = 1;
	while (stack->next != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_ps_aux_display_stacks(t_nb *a, t_nb *b, int oversize)
{
	while (!(a == NULL && b == NULL))
	{
		ft_putchar('\t');
		if (oversize > 0)
		{
			oversize--;
		}
		else
		{
			ft_putnbr(a->n);
			a = a->next;
		}
		ft_putstr("\t|\t");
		if (oversize < 0)
		{
			oversize++;
		}
		else
		{
			ft_putnbr(b->n);
			b = b->next;
		}
		ft_putchar('\n');
	}
}

void	ft_ps_display_stacks(t_nb *stacks[2])
{
	int		oversize;

	oversize = ft_ps_stack_length(*(stacks + 1))
		- ft_ps_stack_length(*(stacks + 0));
	ft_putchar('\n');
	ft_ps_aux_display_stacks(*(stacks + 0), *(stacks + 1), oversize);
	ft_putstr("\t_________________\n\t    a\t|    b\n");
}
