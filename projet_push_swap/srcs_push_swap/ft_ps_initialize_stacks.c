#include "push_swap.h"

void	ft_ps_initialize_stacks(t_nb ***stacks_adress)
{
	t_nb	**stacks;

	stacks = *stacks_adress;
	if (!(stacks = (t_nb **)malloc(2 * sizeof(t_nb *))))
		exit(-1);
	*(stacks + 0) = NULL;
	*(stacks + 1) = NULL;
}
