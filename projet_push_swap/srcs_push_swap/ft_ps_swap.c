#include "push_swap.h"

void	ft_ps_swap(t_nb **stacks, char c)
{
	t_nb	*stack;
	t_nb	*tmp;

	stack = *(stacks + (c - 'a'));
	if (stack != NULL && stack->next != NULL)
	{
		tmp = stack->next;
		stack->next = (stack->next)->next;
		tmp->next = stack;
		*(stacks + (c - 'a')) = tmp;
	}
}
