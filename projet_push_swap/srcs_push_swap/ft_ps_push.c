#include "push_swap.h"

void	ft_ps_push(t_nb **stacks, char c)
{
	t_nb	*tmp;

	tmp = *(stacks + ((c - 'a' + 1) % 2));
	if (tmp != NULL)
	{
		*(stacks + ((c - 'a' + 1) % 2)) = tmp->next;
		tmp->next = *(stacks + (c - 'a'));
		*(stacks + (c - 'a')) = tmp;
	}
}
