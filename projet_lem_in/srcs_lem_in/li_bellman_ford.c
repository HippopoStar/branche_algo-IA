#include "lem_in.h"

void	aux_li_bellman_ford(t_data *data)
{
	size_t	i;
	size_t	j;
	int		wei;

	i = 0;
	while (i < data->size)
	{
		j = 0;
		while (j < data->size)
		{
			if (*((*(data->map + i))->pipes + j) != 0 && i != j)
			{
				wei = (*(data->map + i))->weight + *((*(data->map + i))->pipes + j);
				if (wei < (*(data->map + j))->weight)
				{
					(*(data->map + j))->ancestor = i;
					(*(data->map + j))->weight = wei;
				}
			}
			j++;
		}
		i++;
	}
}

void	li_bellman_ford(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->size)
	{
		aux_li_bellman_ford(data);
		i++;
	}
}
