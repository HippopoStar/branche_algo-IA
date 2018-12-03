#include <stdio.h>
#include "libft.h"
#include "push_swap.h"

void	ft_ps_fill_stacks(t_nb **stacks)
{
	int	a;
	int	b;

	ft_putstr("Donnez le premier element (bas) de la pile A :\n");
	scanf("%i", &a);
	ft_putstr("Donnez le premier element (bas) de la pile B :\n");
	scanf("%i", &b);
	while (!(a == 0 && b == 0))
	{
		if (a != 0)
			ft_ps_add_elem(stacks, 'a', a);
		if (b != 0)
			ft_ps_add_elem(stacks, 'b', b);
		ft_ps_display_stacks(stacks);
		ft_putstr("Donnez successivement les prochains elements de A et de B :\n");
		ft_putstr("un zero etant interprete comme un etage vide\n");
		ft_putstr("OU deux zeros pour terminer le remplissage\n");
		scanf("%i", &a);
		scanf("%i", &b);
	}
}

void	ft_ps_test_apply_moves(t_nb **stacks)
{
	char	command[500];

	ft_putstr("Donnez la premiere operation a realiser :\n");
	ft_putstr("(max 500 caracteres, 'exit' pour quitter)\n");
	scanf("%s", command);
	while (1)
	{
		if (!(ft_strcmp(command, "exit")))
			break ;
		else if (!(ft_strcmp(command, "sa")))
			ft_ps_swap(stacks, 'a');
		else if (!(ft_strcmp(command, "sb")))
			ft_ps_swap(stacks, 'b');
		else if (!(ft_strcmp(command, "ss")))
		{
			ft_ps_swap(stacks, 'a');
			ft_ps_swap(stacks, 'b');
		}
		else if (!(ft_strcmp(command, "pa")))
			ft_ps_push(stacks, 'a');
		else if (!(ft_strcmp(command, "pb")))
			ft_ps_push(stacks, 'b');
		else if (!(ft_strcmp(command, "ra")))
			ft_ps_rotate(stacks, 'a');
		else if (!(ft_strcmp(command, "rb")))
			ft_ps_rotate(stacks, 'b');
		else if (!(ft_strcmp(command, "rr")))
		{
			ft_ps_rotate(stacks, 'a');
			ft_ps_rotate(stacks, 'b');
		}
		else if (!(ft_strcmp(command, "rra")))
			ft_ps_reverse_rotate(stacks, 'a');
		else if (!(ft_strcmp(command, "rrb")))
			ft_ps_reverse_rotate(stacks, 'b');
		else if (!(ft_strcmp(command, "rrr")))
		{
			ft_ps_reverse_rotate(stacks, 'a');
			ft_ps_reverse_rotate(stacks, 'b');
		}
		ft_ps_display_stacks(stacks);
		ft_putstr("Donnez l'operation suivante a realiser ('exit' pour quitter):\n");
		scanf("%s", command);
	}
	ft_putstr("TERMINE ! (en esperant que ca ait ete satisfaisant)\n");
}

int		main(void)
{
	t_nb	**stacks;

	ft_ps_initialize_stacks(&stacks);
	ft_ps_fill_stacks(stacks);
	ft_ps_test_apply_moves(stacks);
	return(0);
}
