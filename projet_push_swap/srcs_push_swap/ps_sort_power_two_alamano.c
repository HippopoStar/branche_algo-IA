#include "push_swap.h"

/*
** En fait, etant donne l'algorithme precedant,
** la pile 'A' contiendra toujours au moins 4 elements
*/

int		ps_get_a_four_lasts(t_ps *data, int *b, int *c, int *d)
{
	int		a;
	t_nb	*tmp;

	tmp = *(data->stacks + 0);
	if (*(data->stacks + 0) != NULL)
	{
		if ((*(data->stacks + 0))->next != NULL)
		{
			if (((*(data->stacks + 0))->next)->next != NULL)
			{
				if ((((*(data->stacks + 0))->next)->next)->next != NULL)
				{
					while ((((tmp->next)->next)->next)->next != NULL)
					{
						tmp = tmp->next;
					}
					*d = (((tmp->next)->next)->next)->nb;
				}
				*c = ((tmp->next)->next)->nb;
			}
			*b = (tmp->next)->nb;
		}
	}
	a = (*(data->stacks + 0) != NULL) ? tmp->nb : 0;
	return (a);
}

void	ps_sort_power_two_alamano(t_ps *data)
{
	size_t	len;

	len = data->length;
	while (len > 7)
	{
		ps_alamano_a(data);
		ps_alamano_b(data);
		len = len - 8;
	}
	if (len > 3)
	{
		ps_alamano_a(data);
		ps_aux_alamano_b(data);
	}
	else if (len > 0)
	{
		ps_aux_alamano_a(data);
	}
}
