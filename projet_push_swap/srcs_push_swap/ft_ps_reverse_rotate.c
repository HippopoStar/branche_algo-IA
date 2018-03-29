#include "push_swap.h"

void	ft_ps_reverse_rotate(t_nb **stacks, char c)
{
	t_nb	*stack;

	stack = *(stacks + (c - 'a'));
	if (stack != NULL && stack->next != NULL)
	{
		while ((stack->next)->next != NULL)
		{
			stack = stack->next;
		}
		(stack->next)->next = *(stacks + (c - 'a'));
		*(stacks + (c - 'a')) = stack->next;
		stack->next = NULL;
	}
}
