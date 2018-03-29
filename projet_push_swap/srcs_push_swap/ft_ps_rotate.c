#include "push_swap.h"

void	ft_ps_rotate(t_nb **stacks, char c)
{
	t_nb	*stack;
	t_nb	*tmp;

	stack = *(stacks + (c - 'a'));
	if (stack != NULL && (tmp = stack->next) != NULL)
	{
		while (stack->next != NULL)
		{
			stack = stack->next;
		}
		stack->next = *(stacks + (c - 'a'));
		(*(stacks + (c - 'a')))->next = NULL;
		*(stacks + (c - 'a')) = tmp;
	}
}
