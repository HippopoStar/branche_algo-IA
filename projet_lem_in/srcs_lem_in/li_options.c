#include "lem_in.h"

int		li_options(t_data *data, int argc, char **argv)
{
	if ((data->options = ft_options(argc, argv, "hcl", 0)) == -1)
	{
		return (0);
	}
	else
	{
		if ((data->options >> ('h' - 'a')) % 2 == 1)
		{
			li_get_output(data, USAGE_MSG);
		}
		data->color = (data->options >> ('c' - 'a')) % 2;
		data->display_steps = (data->options >> ('l' - 'a')) % 2;
	}
	return (1);
}
