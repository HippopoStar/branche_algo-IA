/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_display_stacks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:40:31 by lcabanes          #+#    #+#             */
/*   Updated: 2018/09/19 11:40:35 by lcabanes         ###   ########.fr       */
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

void	ft_ps_display_stacks(t_nb **stacks)
{
	int		oversize;
	t_nb	*a;
	t_nb	*b;

	ft_putchar('\n');
	a = *(stacks + 0);
	b = *(stacks + 1);
	oversize = ft_ps_stack_length(b) - ft_ps_stack_length(a);
	while (!(a == NULL && b == NULL))
	{
		if (oversize > 0)
			oversize--;
		else
		{
			ft_putnbr(a->n);
			a = a->next;
		}
		ft_putstr("\t|\t");
		if (oversize < 0)
			oversize++;
		else
		{
			ft_putnbr(b->n);
			b = b->next;
		}
		ft_putchar('\n');
	}
	ft_putstr("_________________\n    a\t|    b\n");
}
