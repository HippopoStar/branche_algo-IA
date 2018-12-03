#include "push_swap.h"

void		ft_push_swap(t_ps *data, int argc, char **argv)
{
	if (ps_parse(data, argc, argv) == 0)
	{
		ps_display_error();
	}
	else
	{
		ps_sort(data);
	}
}

int		main(int argc, char **argv)
{
	t_ps	data;

	data.verbose = (argc > 2 && !ft_strcmp(*(argv + 1), "-v")) ? 1 : 0;
	if (argc - data.verbose < 2)
	{
		ps_display_error();
	}
	else
	{
		ft_push_swap(&data, argc - data.verbose, argv + data.verbose);
	}
	return (0);
}
