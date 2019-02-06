#include "push_swap.h"

/*
** L'execution de 'ps_position' se passe en partant du postulat de depart
** que la pile 'A' n'est pas vide, et que le nombre recherche se trouve bel
** et bien dans la liste triee elaboree plus tot dans le programme
*/

size_t	ps_position(t_ps *data)
{
	size_t	i;

	i = 0;
	while (*(data->sorted + i) != (*(data->stacks + 0))->nb)
	{
		i++;
	}
	return (i);
}

size_t	ps_get_next_power_of_two(t_ps *data)
{
	size_t	i;

	i = 1;
	while (i < data->length)
	{
		i = 2 * i;
	}
	return (i);
}

void	ps_aux_sort_bis(t_ps *data, size_t to_add, size_t power_two)
{
	size_t	i;
	size_t	j;

	while (power_two > 1)
	{
//		ft_putnbr((int)to_add);		//TODO
//		ft_putchar('\n');			//TODO
		i = 0;
		j = 0;
		while (i < data->length)
		{

			ft_putstr("i: ");
			ft_putnbr((int)i);
			ft_putchar('\n');
			ft_putstr("power_two: ");
			ft_putnbr((int)power_two);
			ft_putchar('\n');
			ft_putstr("ps_position(data): ");
			ft_putnbr((int)ps_position(data));
			ft_putchar('\n');
			ft_putstr("ps_position(data) + to_add: ");
			ft_putnbr((int)(ps_position(data) + to_add));
			ft_putchar('\n');
			ft_putstr("(ps_position(data) + to_add) % power_two: ");
			ft_putnbr((int)((ps_position(data) + to_add) % power_two));
			ft_putchar('\n');
			ps_display_stacks(data->stacks);

			if (*(data->stacks + 0) != NULL && ((ps_position(data) + to_add) % (power_two)) < (power_two / 2))
			{
				ps_print_and_apply(data, "pb");
				j++;
			}
			else
			{
				ps_print_and_apply(data, "ra");
			}
			i++;
		}
//		while (*(data->stacks + 1) != NULL)
		while ((j % (power_two / 2)) > 0)
		{
			ps_print_and_apply(data, "pa");
			j--;
			while ((i % power_two) > 0)
			{
				ps_print_and_apply(data, "rra");
				i--;
			}
		}
		while (i > 0)
		{
			i = i - (j % power_two);

			ft_putstr("i: ");
			ft_putnbr((int)i);
			ft_putchar('\n');
			ft_putstr("j: ");
			ft_putnbr((int)j);
			ft_putchar('\n');
			ft_putstr("power_two: ");
			ft_putnbr((int)power_two);
			ft_putchar('\n');
			ps_display_stacks(data->stacks);

			if (j % (power_two / 2) == j % power_two && (power_two / 2) > 1)
			{
				if (j > 0)
				{
					ps_print_and_apply(data, "pa");
					j--;
					while ((j % (power_two / 2)) > 0)
					{
						ps_print_and_apply(data, "pa");
						j--;
					}
				}
				ps_print_and_apply(data, "rra");
				i--;
				while ((i % power_two) > 0)
				{
					ps_print_and_apply(data, "rra");
					i--;
				}
			}
			else
			{
				ps_print_and_apply(data, "rra");
				i--;
				while ((i % (power_two / 2)) != (data->length % (power_two / 2)))
				{
					ps_print_and_apply(data, "rra");
					i--;
				}
				if (j > 0)
				{
					ps_print_and_apply(data, "pa");
					j--;
					while ((j % (power_two / 2)) > 0)
					{
						ps_print_and_apply(data, "pa");
						j--;
					}
				}
			}
		}
		power_two = power_two / 2;
	}
}

void	ps_sort_bis(t_ps *data)
{
	size_t	power_two;
	size_t	to_add;

	power_two = ps_get_next_power_of_two(data);
	to_add = power_two - data->length;
	ps_aux_sort_bis(data, to_add, power_two);
}
